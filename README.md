# toolite
some little tool for work.

##开发文本对比工具
###解决问题
1. 课堂上存在跟不上打代码速度的问题，勉强跟上又发现产生很多小问题，100左右行的代码找起来很麻烦，想开发这个工具。 
- github的 diff 一样, 能够对比两个文件的不同信息。
###功能描述
- diff [-c] fileName1 fileName2
    对于file2, 在file1中的不同字符。输出提示信息.
    -c 生成合并文件（文件内不同的地方用注释标识出来）

##实现日志（18.7.30）
- fopen函数打开一个文件后，将文件指针赋值给另一文件指针无法记录位置,即打开一次文件只能获取一个文件读取（写入）指针，变换文件指针位置使用fseek()函数

##发现命令（18.7.31）
- 了解到调整文件指针使用fseek()/fwind()两个函数<br>
记录文件指针位置使用fgetpos(stream, &filepos)/fsetpos(stream, &filepos)/ftell(stream).<br>使用的类型是fpos_t.
- 发现存在diff命令可以直接对文件和文件行与行进行对比并显示。
- 至此暂停（推迟）实现diff