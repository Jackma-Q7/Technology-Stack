# Git 安装配置
&emsp;&emsp;在使用 Git 前我们需要先安装 Git。

&emsp;&emsp;Git 目前支持 Linux/Unix、Solaris、Mac和 Windows 平台上运行。

&emsp;&emsp;Git 各平台安装包下载地址为：[http://git-scm.com/downloads](http://git-scm.com/downloads)

## Linux 平台上安装
各大 Linux 平台可以使用包管理器（apt-get、yum 等）进行安装。

Debian/Ubuntu Git 安装最新稳定版本命令为：

```bash
apt-get install git
```

### Centos/RedHat
如果你使用的系统是 Centos/RedHat 安装命令为：

```bash
yum -y install git-core
```

Fedora 安装命令：

```bash
# yum install git (Fedora 21 及之前的版本)
# dnf install git (Fedora 22 及更高新版本)
```

FreeBSD 安装命令：

```bash
pkg install git
```

OpenBSD 安装命令：

```bash
pkg_add git
```

Alpine 安装命令：

```bash
apk add git
```

### 源码安装
&emsp;&emsp;我们也可以在官网下载源码包来安装，最新源码包下载地址：https://mirrors.edge.kernel.org/pub/software/scm/git/ 。

也可以在 GitHub 上克隆源码包：

```bash
git clone https://github.com/git/git
```

解压安装下载的源码包：

```bash
tar -zxf git-1.7.2.2.tar.gz
cd git-1.7.2.2
make prefix=/usr/local all
sudo make prefix=/usr/local install
```

## Windows 平台上安装
&emsp;&emsp;在 Windows 平台上安装 Git 同样轻松，有个叫做 msysGit 的项目提供了安装包，可以到 GitHub 的页面上下载 exe 安装文件并运行：

&emsp;&emsp;安装包下载地址：https://gitforwindows.org/

&emsp;&emsp;直接官网下载也可以：https://git-scm.com/download/win。

&emsp;&emsp;完成安装之后，就可以使用命令行的 git 工具（已经自带了 ssh 客户端）了，另外还有一个图形界面的 Git 项目管理工具。

&emsp;&emsp;在开始菜单里找到 **"Git"->"Git Bash"**，会弹出 Git 命令窗口，你可以在该窗口进行 Git 操作。

&emsp;&emsp;注意环境变量设置了才可以在cmd中运行

### 使用 winget 工具
如果你已经安装了 winget，可以使用以下命令来安装：

```bash
winget install --id Git.Git -e --source winget
```

## Mac 平台上安装
通过 Homebrew 安装：

```bash
brew install git
```

&emsp;&emsp如果您想要安装 git-gui 和 gitk（git 的提交 GUI 和交互式历史记录浏览器），您可以使用 homebrew 进行安装：

```bash
brew install git-gui
```

也可以使用图形化的 Git 安装工具，下载地址为：

https://sourceforge.net/projects/git-osx-installer/(https://sourceforge.net/projects/git-osx-installer/)

## Git 配置
&emsp;&emsp;Git 提供了一个叫做 **git config** 的命令，用来配置或读取相应的工作环境变量。

&emsp;&emsp;这些环境变量，决定了 Git 在各个环节的具体工作方式和行为。

这些变量可以存放在以下三个不同的地方：

+ `/etc/gitconfig` 文件：系统中对所有用户都普遍适用的配置。若使用 `git config` 时用 `--system` 选项，读写的就是这个文件。
+ `~/.gitconfig` 文件：用户目录下的配置文件只适用于该用户。若使用 `git config` 时用 `--global` 选项，读写的就是这个文件。
+ 当前项目的 Git 目录中的配置文件（也就是工作目录中的 `.git/config` 文件）：这里的配置仅仅针对当前项目有效。每一个级别的配置都会覆盖上层的相同配置，所以 `.git/config` 里的配置会覆盖 `/etc/gitconfig` 中的同名变量。

&emsp;&emsp;在 Windows 系统上，Git 会找寻用户主目录下的 .gitconfig 文件。主目录即 $HOME 变量指定的目录，一般都是 C:\Documents and Settings\$USER。

&emsp;&emsp;此外，Git 还会尝试找寻 /etc/gitconfig 文件，只不过看当初 Git 装在什么目录，就以此作为根目录来定位。

### 用户信息
配置个人的用户名称和电子邮件地址，这是为了在每次提交代码时记录提交者的信息：

```git
git config --global user.name "runoob"
git config --global user.email test@runoob.com
```

&emsp;&emsp;如果用了 **--global** 选项，那么更改的配置文件就是位于你用户主目录下的那个，以后你所有的项目都会默认使用这里配置的用户信息。

&emsp;&emsp;如果要在某个特定的项目中使用其他名字或者电邮，只要去掉 --global 选项重新配置即可，新的设定保存在当前项目的 .git/config 文件里。

### 文本编辑器
&emsp;&emsp;设置 Git 默认使用的文本编辑器,一般可能会是 Vi 或者 Vim，如果你有其他偏好，比如 VS Code 的话，可以重新设置：

```git
git config --global core.editor "code --wait"
```

### 差异分析工具
&emsp;&emsp;还有一个比较常用的是，在解决合并冲突时使用哪种差异分析工具。比如要改用 vimdiff 的话：

```git
git config --global merge.tool vimdiff
```

&emsp;&emsp;Git 可以理解 kdiff3，tkdiff，meld，xxdiff，emerge，vimdiff，gvimdiff，ecmerge，和 opendiff 等合并工具的输出信息。

&emsp;&emsp;当然，你也可以指定使用自己开发的工具，具体怎么做可以参阅第七章。

### 查看配置信息
要检查已有的配置信息，可以使用 **git config --list** 命令：

```git
git config --list
http.postbuffer=2M
user.name=runoob
user.email=test@runoob.com
```

有时候会看到重复的变量名，那就说明它们来自不同的配置文件（比如 /etc/gitconfig 和 ~/.gitconfig），不过最终 Git 实际采用的是最后一个。

这些配置我们也可以在 **~/.gitconfig** 或 **/etc/gitconfig** 看到，如下所示：

```git
vim ~/.gitconfig 
```

显示内容如下所示：

```plain
[http]
    postBuffer = 2M
[user]
    name = runoob
    email = test@runoob.com
```

也可以直接查阅某个环境变量的设定，只要把特定的名字跟在后面即可，像这样：

```git
git config user.name
Jackma
```

### 生成 SSH 密钥（可选）
&emsp;&emsp;配置链接远程仓库
&emsp;&emsp;如果你需要通过 SSH 进行 Git 操作，可以生成 SSH 密钥并添加到你的 Git 托管服务（如 GitHub、GitLab 等）上。

```git
ssh-keygen -t rsa -b 4096 -C "your.email@example.com"
```

按提示完成生成过程，然后将生成的公钥添加到相应的平台。

### 验证安装
在终端或命令行中运行以下命令，确保 Git 已正确安装并配置：

```git
git --version
git config --list
```