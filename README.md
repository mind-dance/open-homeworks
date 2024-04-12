# open-homeworks

voilà! 欢迎来到开放作业库，这里致力于收集高可复用的作业，通过提供通用的代码与文档，供有需要的同学自行修改并使用。希望能为你们提供一点参考。

鉴于同学们最终交作业基本都会上交源代码，并且对直接打包本库售卖做一些限制，本仓库使用GPL-2或更高版本。

文档协议为CC4.0-BY-SA

对于希望代码更简单一些，以方便课程的答辩等个性化需求，可以前往薯条港科学院有偿寻求个性化技术响应。

如果你也想加入个性化技术响应团队，可以联系薯条港科学院，我们会为你分配工单，仅仅抽取一些税费用于补贴服务器租赁等费用。对于有一定贡献的开发者免税（例如为本项目提PR并通过）。

目前规划收集如下

| 项目             | C               | Java | Python |
| ---------------- | --------------- | ---- | ------ |
| 学生信息管理系统 | 命令行；QT；web |      |        |
|                  |                 |      |        |
|                  |                 |      |        |

C语言：

- [ ] 学生信息管理系统
- [ ] 月历
- [ ] 图书管理系统

数据结构：

- [ ] 车票管理系统
- [ ] 校园地图导览
- [ ] 散列表查找

Java面相对象：

- 小游戏
  - [ ] 飞机大战
  - [ ] 连连看
  - [ ] 贪吃蛇

Python：


（待开发）（付费）代码自动裁剪器

输入需求，自动为你裁剪代码。并输出。


FAQ：

Q：这个项目是否会养成学生的惰性？让学生失去了编写代码的经历，没办法起到培养学生能力的作用？

A：我认为，本项目足够复杂，如果没有一定的编程功底，可能无法独立修改以适配需求。换言之，如果该学生能使用本项目的代码裁剪为合适的代码，那么该学生具备了查找资料、编写该代码、调试测试的能力，即使没有本项目，该学生应该也能通过chatGPT等其他渠道轻松的完成该作业。



# 开发指南

你需要一些工具

版本控制工具：git

代码编辑器：强烈推荐visual studio code（简称vscode）

vscode基本可以承包你从大一到大四的代码。如果你有自己觉得顺手并且可以独立处理疑难杂症，可以考虑其他ide，例如idea。本仓库中只有少数过时技术（例如jsp）的代码需要其他ide或代码编辑器，相关项目的文件夹下会提及。

代理工具：推荐clash系列或者v2ray系列

（可选）一个outlook邮箱

（可选）一个matrix账号

（可选）一个github账号

## 如何提交代码？
使用git连接仓库，首先`git init`在目标位置初始化仓库。如果第一次使用git还需要设置用户名和邮箱
```
git config --global user.email "your email"
git config --global user.name "your name"
```
连接本仓库使用命令如下
```
git add origin https://github.com/mind-dance/open-homeworks.git
git pull origin main
```
需要在git终端设置代理。
我使用的是HTTPS连接，ssh连接请自行寻找方法。
例如clash开启局域网代理后，混合代理端口为7890。则我的命令如下

设置全局代理
```bash
git config --global https.proxy http://127.0.0.1:7890
```

仅对github设置代理（https）
```bash
git config --global https.https://github.com.proxy http://127.0.0.1:7890
# git config --global http.https://github.com.proxy socks5://127.0.0.1:7890
```

若需要取消代理则使用
```
git config --global --unset https.proxy
```
