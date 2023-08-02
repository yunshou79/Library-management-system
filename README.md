# Library-management-system
C++
该系统使用C++语言编写
结构设计：
![Company Stru00cture](https://github.com/yunshou79/Library-management-system/assets/132857445/134470ad-46c2-4b75-ac1d-39aeb77e1eda)
功能结构图：
![image](https://github.com/yunshou79/Library-management-system/assets/132857445/a8435762-09e4-4a6e-ba25-5e6f9827c98d)

功能流程及工作流描述：

  1、void AddBook(book NewBook); //增加图书

  2、void DeleteBook(string bookname, string author);//删除图书
  
  3、void ShowAllBook(); //输出系统所有图书
  
  4、void SearchBookPosWithname(string thebook); //按书名查询
  
  5、void SearchBookPosWithAuthor(string theauthor);//按作者查询
  
  6、int SearchBookPosWithNum(int theNum);//按编号查询
  
  7、void SortBook(int ca); //排序
  
  8、void Save(); //存入图书馆文件
  
  9、void printbook(book a);//输出某本书的所有信息
  
  10、void revisebook(string name, string author);//修改某本书的信息
  
数据库设计：

数据库结构体Bookdate，以txt文件存储数据，高效便捷，且兼容性强，booklib以顺序链表存储数据

详细设计：

  a)在字符串接收部分：将所有大写字母转换为小写，该方式通过unifiedWord函数接收字符串。
  
  b)在命令处理部分主要有以下几种：
  
    i.通过2命令-读者开始输入地址，若加载成功 返回值true。
	
    ii.通过5命令-根据名称和作者名字等关键字输入查找依据与查找内容。
	
    iii.通过2命令-借此传入参数。
	
    iv.通过3命令-根据名称和作者名字输入删除依据与删除内容。
	
    v.通过6命令-则依据作者姓名排序，在排序过程中需要调用data库和相关函数。
	
