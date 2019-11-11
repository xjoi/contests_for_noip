#### 普通情况
config文件中写入`@regex test ([a-zA-Z]*[1-9][0-9]*)[.]in \1[.]out`后，上传到题目中即可。（正则表达）
#### 复杂情况
将配置文件按如下例子编写后（注意缩进是严格的），命名成`conf.cson`文件后，上传到题目中即可。  
补充说明:若同时存在`config`文件和`conf.cson`文件,`config`文件配置优先.
```yml
# XJOI目前的config是这样的：
# 当然，该文件可以用同语意的 json、toml、yaml 来替代
# 将配置文件命名为 conf.json / conf.cson / conf.toml / conf.yaml，放置于数据文件夹下

# 所有关键字均可简写为任意前缀
# 所有列表均可以省略为单一元素

version: 1000
# 版本号
# 可选，默认为 1000
# 为以后无法兼容的更新做准备

timeLimit: 1000
# 全局时间限制
# 可选，默认为 1000

memoryLimit: 524288
# 全局空间限制
# 可选，默认为 524288

extraTime: 0
# 交互程序用时上限
# 可选，默认为 0
# 用于生成程序 real time 上限

subtasks: [
    {
        name: 1
        # 测试集编号
        # 可选，默认为测试集序号

        cases: [
            101
            "102"
            "1[03-10]"
        ]
        # 测试点编号 -> 弱化版的正则表达式

        points: 25
        # 测试集分数
        # 可选，默认为 100

        rule: "sum"
        # 计分类型，可选的值有 sum、min 和 mul
        # 可选，默认为 min

        dependences: []
        # 测试点依赖
        # 可选，默认为空

        timeLimit: 1000
        # 本测试集测试点时间限制（ms）
        # 可选，默认为全局时间限制

        memoryLimit: 524288
        # 本测试集测试点空间限制（kb）
        # 可选，默认为全局空间限制
    }
    {
        n: "2"
        # 测试集编号也可以为字符串
        c: "2[01-10]"
        p: 25
        r: "mul"
        d: 1
        t: 2000
        m: 262144
    }
    {
        c: 301
        d: ["1",2]
        p: 50
    }
]
# 测试点信息

build: [
    {
        target: "program"
        # 目标程序
        # 可选，默认为 program

        input: ["program"]
        # 联合编译文件列表
        # 省略文件后缀名
        # 可选，默认为 ["program"]

        arguments: ["-O2"]
        # 运行参数列表
        # 可选，默认为 ["-O2"]
    }
    # 可以编译多个文件
    # 编译时，一份 xjoj 版的 testlib 将会被放置于目录下
]
# 编译命令
# 可选，默认值与上面的一致

run: [
    {
        target: "program"
        # 目标程序
        # 可选，默认为 program

        input: "in"
        # 输入文件重定向
        # 可选，默认为 /dev/null

        output: "out"
        # 输出文件重定向
        # 可选，默认为 /dev/null

        readable: []
        # 可读文件列表
        # 可选，默认为空

        writable: []
        # 可写文件列表
        # 可选，默认为空

        arguments: []
        # 运行参数列表
        # 可选，默认为空

        # 所有不存在的文件，除output的外，都会被视作fifo（有名管道）处理
    }
    # 所有程序将会同步运行
]
# 运行命令
# 可选，默认值与上面的一致

check:
    target: "wcmp"
    # 可选，默认为 wcmp

    input: "in"
    # 可选，默认为 in

    output: "out"
    # 可选，默认为 out

    answer: "ans"
    # 可选，默认为 ans

# 自定义比较器参数
# 可选，默认值与上面的一致

aliases: [    #重命名
    {
        to: "in"
        # 评测时的名字

        from: "data#.in"
        # 原名
        # 可选，默认为评测时的名字
    }
    {
        to: "ans"
        from: "data#.ans"
    }
    {
        to: "grader.cpp"
        from: "grader.cpp"
    }
    {
        to: "interactor.h"
        from: "interactor.h"
    }
]
# 评测中需要改名的文件
# 井号为当前测试点编号
# 可选，默认值为空

# 接下来是一些例子：

EXAMPLE1:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    a: [
        { t: "in", f: "data#.in", }
        { t: "ans", f: "data#.ans" }
    ]

# A+B长这样

EXAMPLE2:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    r:
        r: ["data.in"]
        w: ["data.out"]
    c:
        t: "wcmp"
        i: "data.in"
        o: "data.out"
        a: "data.ans"
    a: [
        { t: "data.in", f: "data#.in" }
        { t: "data.ans", f: "data#.ans" }
    ]

# 文件输入输出的A+B长这样

EXAMPLE3:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    r: [
        {
            i: "PIPE1"
            o: "PIPE2"
        }
        {
            t: "interactor"
            i: "PIPE2"
            o: "PIPE1"
            r: ["in"]
            w: ["out"]
            a: ["in", "out"]
        }
    ]
    a: [
        { t: "in", f: "data#.in", }
        { t: "ans", f: "data#.ans" }
    ]

# CF/ATC交互的A+B长这样

EXAMPLE4:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    b:
        i: ["program", "grader"]
    a: [
        { t: "in" , f: "data#.in" }
        { t: "ans" , f: "data#.ans" }
    ]

# 传统交互的A+B长这样

EXAMPLE5:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    b: []
    r: []
    a: [
        { t: "in" , f: "data#.in" }
        { t: "out" , f: "data#.out" }
        { t: "ans" , f: "data#.ans" }
    ]

# 提交答案题长这样

EXAMPLE6:
    t: 200
    m: 65536
    s:
        c: "[1-10]"
        r: "sum"
    b:
        i: ["program", "grader"]
    r: [
        {
            o: "PIPE1"
            a: ["encode"]
        }
        {
            i: "PIPE1"
            a: ["decode"]
        }
    ]
    a: [
        { t: "in", f: "data#.in", }
        { t: "ans", f: "data#.ans" }
    ]

# 传输题长这样

EXAMPLE7:
    t: 1000
    m: 262144
    s: [
        {
            c: "1_[01-20]"
            p: 9
        }
        {
            c: "2_[01-20]"
            p: 22
        }
        {
            c: "3_[01-20]"
            p: 27
        }
        {
            c: "4_[01-20]"
            p: 42
            d: [1, 2, 3]
        }
    ]
    a: [
        { t: "in" }
        { t: "ans" }
    ]

# 这是某道APIO题->就是boat啦
```
