# C++之STL模板库1-20
## 1、什么是STL？
C++ STL从广义来讲包括了三类：算法，容器和迭代器。

+ 算法包括排序，复制等常用算法，以及不同容器特定的算法。
+ 容器就是数据的存放形式，包括序列式容器和关联式容器，序列式容器就是list，vector等，关联式容器就是set，map等。
+ 迭代器就是在不暴露容器内部结构的情况下对容器的遍历。

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

    // =========================
    // 1. 序列式容器 vector
    // =========================
    vector<int> nums = {5, 2, 8, 1, 9};

    // 使用算法 sort 排序
    sort(nums.begin(), nums.end());

    cout << "vector 排序后: ";

    // 使用迭代器遍历
    vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    // =========================
    // 2. 序列式容器 list
    // =========================
    list<string> names;

    names.push_back("Tom");
    names.push_back("Jack");
    names.push_back("Alice");

    cout << "list 内容: ";

    // 使用迭代器遍历
    list<string>::iterator lit;
    for (lit = names.begin(); lit != names.end(); ++lit) {
        cout << *lit << " ";
    }
    cout << endl;


    // =========================
    // 3. 关联式容器 set
    // =========================
    set<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(3); // 重复元素不会插入

    cout << "set 内容: ";

    // set 会自动排序
    for (set<int>::iterator sit = s.begin(); sit != s.end(); ++sit) {
        cout << *sit << " ";
    }
    cout << endl;


    // =========================
    // 4. 关联式容器 map
    // =========================
    map<string, int> score;

    score["Tom"] = 90;
    score["Alice"] = 95;
    score["Jack"] = 85;

    cout << "map 内容: " << endl;

    // map 迭代器
    for (map<string, int>::iterator mit = score.begin();
         mit != score.end(); ++mit) {

        cout << mit->first << " : "
             << mit->second << endl;
    }


    // =========================
    // 5. 算法 find
    // =========================
    vector<int>::iterator pos;//但它不是普通指针，而是 STL 的迭代器。

    pos = find(nums.begin(), nums.end(), 8);

    if (pos != nums.end()) {
        cout << "找到元素 8" << endl;
    } else {
        cout << "未找到元素 8" << endl;
    }

    return 0;
}
```

## 2、解释一下什么是trivial destructor
“trivial destructor”（ 平凡析构函数  ）一般是指用户没有自定义析构函数，而由系统生成的，这种析构函数在《STL源码解析》中成为“无关痛痒”的析构函数。

反之，用户自定义了析构函数，则称之为“non-trivial destructor”，这种析构函数**如果申请了新的空间一定要显式的释放，否则会造成内存泄露**

对于trivial destructor，如果每次都进行调用，显然对效率是一种伤害，如何进行判断呢？

《STL源码解析》中给出的说明是:

首先利用value_type()获取所指对象的型别，再利用__type_traits判断该型别的析构函数是否trivial，若是(__true_type)，则什么也不做，若为(__false_type)，则去调用destory()函数。

也就是说，在实际的应用当中，STL库提供了相关的判断方法**__type_traits**，感兴趣的读者可以自行查阅使用方式。除了trivial destructor，还有trivial construct、trivial copy construct等，如果能够对是否trivial进行区分，可以采用内存处理函数memcpy()、malloc()等更加高效的完成相关操作，提升效率。

```cpp
#include <iostream>
#include <type_traits>
#include <cstring>

using namespace std;

// trivial destructor（平凡析构）
// 编译器自动生成析构函数
class A {
public:
    int x;
};

// non-trivial destructor（非平凡析构）
// 用户自定义析构函数
class B {
private:
    int* p;

public:
    B() {
        p = new int(100);
    }

    ~B() {
        delete p;
        cout << "B 析构函数被调用" << endl;
    }
};

int main() {

    cout << boolalpha;

    // 判断是否为平凡析构
    cout << "A 是否 trivial destructor: "
         << is_trivially_destructible<A>::value
         << endl;

    cout << "B 是否 trivial destructor: "
         << is_trivially_destructible<B>::value
         << endl;

    // trivial 类型可以直接 memcpy
    int a[5] = {1,2,3,4,5};
    int b[5];

    memcpy(b, a, sizeof(a));

    cout << "memcpy 后的数据: ";

    for (int x : b) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
```

1. trivial destructor 示例

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int x;
};

int main() {
    A a;
    a.x = 10;

    cout << a.x << endl;

    return 0;
}
```

这里：

```cpp
class A
```

没有写析构函数：

```cpp
~A()
```

所以：

```plain
编译器自动生成析构函数
```

这种就是：

trivial destructor（平凡析构）

它实际上什么都没做。

等价于：

```cpp
~A() {}
```

但编译器知道：

```plain
它没有资源需要释放
```

因此 STL 可以：

```plain
直接跳过析构
```

提升效率。

2. non-trivial destructor 示例

```cpp
#include <iostream>
using namespace std;

class B {
private:
    int* p;

public:
    B() {
        p = new int(100);
        cout << "构造函数" << endl;
    }

    ~B() {
        delete p;
        cout << "析构函数" << endl;
    }
};

int main() {

    B b;

    return 0;
}
```

这里：

```cpp
~B()
```

是用户自己写的。

因此：

non-trivial destructor

因为：

```plain
析构时需要释放资源
```

如果不调用：

```cpp
delete p;
```

就会：

内存泄漏

3. STL 为什么要区分？

例如 vector 删除元素时：

```cpp
vector<T>
```

可能有一百万个对象。

如果：

```plain
每个对象都调用析构函数
```

但它实际上什么都不做：

```plain
就浪费性能
```

因此 STL 会判断：

```plain
这个类型是否 trivial destructor
```

4. C++ 现代写法（type_traits）

现代 C++ 用：

```cpp
std::is_trivially_destructible
```

判断。

示例：

```cpp
#include <iostream>
#include <type_traits>

using namespace std;

class A {
public:
    int x;
};

class B {
public:
    ~B() {
    }
};

int main() {

    cout << boolalpha;

    cout << "A 是否平凡析构: "
         << is_trivially_destructible<A>::value
         << endl;

    cout << "B 是否平凡析构: "
         << is_trivially_destructible<B>::value
         << endl;

    return 0;
}
```

输出：

```cpp
A 是否平凡析构: true
B 是否平凡析构: false
```

5. STL 的优化思想（核心）

STL 内部大概类似：

```cpp
if (类型是 trivial destructor)
{
    // 什么都不做
}
else
{
    // 调用析构函数
}
```

这样：

```cpp
简单类型走 memcpy
复杂类型走构造/析构
```

效率非常高。

6. memcpy 优化示例

对于：

```cpp
int
char
double
struct POD
```

这种 trivial 类型：

可以直接：

```cpp
memcpy()
```

例如：

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int a[5] = {1,2,3,4,5};
    int b[5];

    memcpy(b, a, sizeof(a));

    for (int x : b) {
        cout << x << " ";
    }

    return 0;
}
```

因为 int 是 trivial copy construct：

所以可以直接内存拷贝。

7. STL源码中的 __type_traits

早期 STL：

```cpp
__type_traits<T>
```

内部类似：

```cpp
typedef __true_type has_trivial_destructor;
```

或者：

```cpp
typedef __false_type has_trivial_destructor;
```

然后：

```cpp
__destroy(first, last, type);
```

根据类型选择不同实现。

这就是：

类型萃取（Type Traits）

也是：

```plain
泛型编程核心技术
```

8. 总结

trivial destructor

特点：

+  编译器自动生成 
+  不释放资源 
+  可以跳过析构 
+  可以 memcpy 

例如：

```cpp
int
double
普通struct
```

non-trivial destructor

特点：

+  用户自定义析构 
+  需要释放资源 
+  必须调用析构函数 

例如：

```cpp
含 new/delete 的类
含文件句柄
含 socket
```

STL 的核心优化思想

```cpp
能 memcpy 就 memcpy
能不析构就不析构
```

利用：

```plain
type traits（类型萃取）
```

在编译期完成判断。

## 3、使用智能指针管理内存资源，RAII是怎么回事？
1. RAII全称是“Resource Acquisition is Initialization”，直译过来是“资源获取即初始化”，也就是说在构造函数中申请分配资源，在析构函数中释放资源。

因为C++的语言机制保证了，当一个对象创建的时候，自动调用构造函数，当对象超出作用域的时候会自动调用析构函数。所以，在RAII的指导下，我们应该使用类来管理资源，将资源和对象的生命周期绑定。

2. 智能指针（std::shared_ptr和std::unique_ptr）即RAII最具代表的实现，使用智能指针，可以实现自动的内存管理，再也不需要担心忘记delete造成的内存泄漏。

毫不夸张的来讲，有了智能指针，代码中几乎不需要再出现delete了。

## 4、迭代器：++it、it++哪个好，为什么
1. 前置返回一个引用，后置返回一个对象

```cpp
//++i实现代码为:
int& operator++()
{
    *this += 1;
    return *this;
}
```

2. 前置不会产生临时对象，后置必须产生临时对象，临时对象会导致效率降低

```cpp
//i++实现代码为:

int operator++(int)
{
    int temp = *this;
    
    ++*this;
        
    return temp;
}
```

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = {10, 20, 30};

    // 前置 ++it
    // 直接让迭代器自增
    // 返回迭代器本身（引用）
    // 不产生临时对象
    cout << "前置 ++it : ";
    for (vector<int>::iterator it = nums.begin();
        it != nums.end();
        ++it)
        {
            cout << *it << " ";
        }

    cout << endl;

    // 后置 it++
    // 先保存旧值
    // 再自增
    // 返回旧对象（临时对象）
    // 会产生额外开销
    cout << "后置 it++ : ";
    for (vector<int>::iterator it = nums.begin();
        it != nums.end();
        it++)
        {
            cout << *it << " ";
        }

    cout << endl;

    return 0;
}
```

关键点在于：

```plain
“返回旧值” 和 “it 自己已经 +1”
是两回事。
```

看这个例子：

```cpp
int i = 10;

int x = i++;
```

执行过程：

```plain
1. 先保存旧值 10
2. i 自己变成 11
3. 返回旧值 10 给 x
```

结果：

```cpp
i = 11
x = 10
```

## 5、说一下C++左值引用和右值引用
C++11正是通过引入右值引用来优化性能，具体来说是通过移动语义来避免无谓拷贝的问题，通过move语义来将临时生成的左值中的资源无代价的转移到另外一个对象中去，通过完美转发来解决不能按照参数实际类型来转发的问题（同时，完美转发获得的一个好处是可以实现移动语义）。

1. 在C++11中所有的值必属于左值、右值两者之一，右值又可以细分为纯右值、将亡值。在C++11中可以取地址的、有名字的就是左值，反之，不能取地址的、没有名字的就是右值（将亡值或纯右值）。

举个例子，int a = b+c, a 就是左值，其有变量名为a，通过&a可以获取该变量的地址；表达式b+c、函数int func()的返回值是右值，在其被赋值给某一变量前，我们不能通过变量名找到它，＆(b+c)这样的操作则不会通过编译。

2. C++11对C++98中的右值进行了扩充。在C++11中右值又分为纯右值（prvalue，Pure Rvalue）和将亡值（xvalue，eXpiring Value）。

其中纯右值的概念等同于我们在C++98标准中右值的概念，指的是临时变量和不跟对象关联的字面量值；将亡值则是C++11新增的跟右值引用相关的表达式，这样表达式通常是将要被移动的对象（移为他用），比如返回右值引用T&&的函数返回值、std::move的返回值，或者转换为T&&的类型转换函数的返回值。将亡值可以理解为通过“盗取”其他变量内存空间的方式获取到的值。在确保其他变量不再被使用、或即将被销毁时，通过“盗取”的方式可以避免内存空间的释放和分配，能够延长变量值的生命期。

3. 左值引用就是对一个左值进行引用的类型。右值引用就是对一个右值进行引用的类型，事实上，由于右值通常不具有名字，我们也只能通过引用的方式找到它的存在。

右值引用和左值引用都是属于引用类型。无论是声明一个左值引用还是右值引用，都必须立即进行初始化。而其原因可以理解为是引用类型本身自己并不拥有所绑定对象的内存，只是该对象的一个别名。左值引用是具名变量值的别名，而右值引用则是不具名（匿名）变量的别名。

左值引用通常也不能绑定到右值，但**常量左值引用**是个“万能”的引用类型。它可以接受非常量左值、常量左值、右值对其进行初始化。不过常量左值所引用的右值在它的“余生”中只能是只读的。相对地，非常量左值只能接受非常量左值对其进行初始化。

4. 右值值引用通常不能绑定到任何的左值，要想绑定一个左值到右值引用，通常需要std::move()将左值强制转换为右值。

**左值和右值**

左值：表示的是可以获取地址的表达式，它能出现在赋值语句的左边，对该表达式进行赋值。但是修饰符const的出现使得可以声明如下的标识符，它可以取得地址，但是没办法对其进行赋值

```cpp
 const int& a = 10;
```

右值：表示无法获取地址的对象，有常量值、函数返回值、lambda表达式等。无法获取地址，但不表示其不可改变，当定义了右值的右值引用时就可以更改右值。

**左值引用和右值引用**

左值引用：传统的C++中引用被称为左值引用

右值引用：C++11中增加了右值引用，右值引用关联到右值时，右值被存储到特定位置，右值引用指向该特定位置，也就是说，右值虽然无法获取地址，但是右值引用是可以获取地址的，该地址表示临时对象的存储位置

**这里主要说一下右值引用的特点：**

+ 特点1：通过右值引用的声明，右值又“重获新生”，其生命周期与右值引用类型变量的生命周期一样长，只要该变量还活着，该右值临时量将会一直存活下去
+ 特点2：右值引用独立于左值和右值。意思是右值引用类型的变量可能是左值也可能是右值
+ 特点3：T&& t在发生自动类型推断的时候，它是左值还是右值取决于它的初始化。

举个例子：

```cpp
void fun(T&& t)
{
	cout << t << endl;
}

int getInt()
{
	return 5;
}

int main() {
	
	int a = 10;
	int& b = a;  //b是左值引用
	int& c = 10;  //错误，c是左值引用不能使用右值初始化
	int&& d = 10;  //正确，右值引用用右值初始化
	int&& e = a;  //错误，e是右值引用不能使用左值初始化
	const int& f = a; //正确，左值常引用相当于是万能型，可以用左值或者右值初始化
	const int& g = 10;//正确，左值常引用相当于是万能型，可以用左值或者右值初始化
	const int&& h = 10; //正确，右值常引用
	const int& aa = h;//正确
	int& i = getInt();  //错误，i是左值引用不能使用临时变量（右值）初始化
	int&& j = getInt();  //正确，函数返回值是右值
	fun(10); //此时fun函数的参数t是右值
	fun(a); //此时fun函数的参数t是左值
	return 0;
}
```