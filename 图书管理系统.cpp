#include<iostream>
#include<windows.h>//与 system("cls");连用实现清屏操作
#include <fstream>//对文件进行操作所包含的头文件
#include<stdio.h>//使用Sleep()需包含的头文件
#include <cstring>
#include<iomanip>
using namespace std;
const unsigned  short MAX =11;
class book
{
private:
    string bookEntrynumber;//书籍登录号
    string bookname;//书籍名称
    string authorname;//作者姓名
    string booktype;// 书籍分类
    string publishaddress;//书籍出版单位
    string  publishtime;//书籍出版时间
    string bookprice;//书籍价格
public:
    book* next;
    string getbookEntrynumber()//get函数实现private数据在类外调用
    {
        return bookEntrynumber;
    }
    string getbookname()
    {
        return bookname;
    }
    string getauthorname()
    {
        return authorname;
    }
    string getbooktype()
    {
        return booktype;
    }
    string getpublishaddress()
    {
        return publishaddress;
    }
    string getpublishtime()
    {
        return publishtime;
    }
    string getbookprice()
    {
        return bookprice;
    }
    friend istream& operator>>(istream& in, book& p);//重载输入
    friend ostream& operator<<(ostream& out, book& p);//重载输出
    void  m_bookEntrynumber()//输入图书数据 book_Entry_number
    {
        cin >> bookEntrynumber;
    }
    void m_bookname()// 输入图书数据book_name
    {
        cin >> bookname;
    }
    void m_authorname()// 输入图书数据author_name
    {
        cin >> authorname;
    }
    void m_booknumber()// 输入图书数据book_number
    {
        cin >> booktype;
    }
    void m_publishaddress()// 输入图书数据publish_address
    {
        cin >> publishaddress;
    }
    void m_publishtime()// 输入图书数据publish_time
    {
        cin >> publishtime;
    }
    void m_bookprice()// 输入图书数据book_price
    {
        cin >> bookprice;
    }
    void Exchangebook(book* q);//进行图书信息交换
};
istream& operator>>(istream& in, book& p)//实现重载输入
{
    in >> p.bookEntrynumber >> p.bookname >> p.authorname >> p.booktype >> p.publishaddress >> p.publishtime >> p.bookprice;
    return in;
}
ostream& operator<<(ostream& out, book& p)//实现重载输出 （固定输出数据宽度为MAX,左对齐，
{
    out << setw(MAX) << setiosflags(ios::left) << p.bookEntrynumber << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.bookname << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.authorname << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.booktype << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.publishaddress << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.publishtime << "\t\t";
    out << setw(MAX) << setiosflags(ios::left) << p.bookprice << endl;
    return out;
}
class LibraryManager//图书馆管理类
{
public:
    LibraryManager();//图书管理类的构造函
    void Menu();//图书管理系统菜单
    void ExitManager();//退出系统
    void Addbook(book** q);//增加图书信息
    void showbook(book* q);//显示图书信息
    void Deletebook(book** q);//删除图书信息
    void amendbook(book* q);//修改图书信息
    void FINDbook(book* q);//查找图书信息
    void sortbook(book* q);//按照图书价格排序
    void Exchangebook(book* q);//排序时用来信息交换
    void SaveData(book* q);//将图书数据保存在新文件中
    int  initbook(book** q);//从文件中读出图书信息
private:
    book* abook;//book类指针指向链表头
    book* zbook;//book类指针指向链表尾
};
LibraryManager::LibraryManager()//图书管理类的构造函数
{
    abook = NULL;
    initbook(&abook);//将链表头部地址传给 init_book
}
int  LibraryManager::initbook(book** q)//从文件中读出图书信息
{
    int j = 0;//用来计录读取信息数
    ifstream infile("书籍信息.txt", ios::in);//从书籍信息.txt文件中读取数据
    if (!infile)
    {
        cout << "书籍载入失败" << endl; //书籍载入失败
        Sleep(200);
        system("cls");
        return 0;
    }
    while (!infile.eof())
    {
        book* temp;
        temp = new book;
        infile >> (*temp);
        if (infile.eof()) { break; }//读取到文件尾，结束
        j++;
        if (*q == NULL)//检查链表是否为空链表
        {
            temp->next = NULL;
            *q = temp;
        }
        else
        {
            temp->next = NULL;
            (zbook)->next = temp;
        }
        zbook = temp;
    }
    if (j == 0) {
        cout << "书籍文件为空" << endl;
        Sleep(200);
        system("cls");
    }
    else 
    {
        cout << "从文件中读取数据" << endl;
        Sleep(300);
        system("cls");
    }
    infile.close();
    return 1;
}
void LibraryManager::Menu()
{
    cout << "------------欢迎使用图书信息管理系统------------------" << endl;
    cout << "        1---增加图书信息      2---显示图书信息 " << endl;
    cout << "        3---删除图书信息      4---修改图书信息 " << endl;
    cout << "        5---查找图书信息      6---按照价格排序 " << endl;
    cout << "        7--图书数据保存在新文件中并退出系统" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "请输入您的选择--->";
    char  m;
    try 
    {
        cin >> m;
        if (m < '1' || m>'8') throw - 1;
    }
    catch (int)
    {
        cout << "输入有误，请重新输入" << endl;
        cin >> m;
    }
    switch (m)//根据用户的选择进行功能实现
    {
    case '1':  Addbook(&abook); break;//增加图书信息
    case '2':  showbook(abook); break;//显示图书信息
    case '3':  Deletebook(&abook); break;//删除图书信息
    case '4':  amendbook(abook); break;//修改图书信息
    case '5':  FINDbook(abook); break;//查找图书信息
    case '6':  sortbook(abook); break;//按照登录号排序
    case '7':  SaveData(abook); cout << "欢迎下次使用" << endl; exit(0); break;//将图书数据保存在新文件中
    case '8':  initbook(&abook); break;
    }
}//从文件中读出图书信息
void  LibraryManager::Addbook(book** q)//增加图书信息
{
    char m;
    cout << "请输入图书信息" << endl;
    book* p;//定义book类指针
    p = new book;//为p申请存储空间
    cout <<"本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
    cin >> *p;
    if (*q == NULL)//检查链表是否为空链表
    {
        p->next = NULL;
        *q = p;
    }//如果链表为空则把链表头指向p
    else
    {
        p->next = NULL;//p是倒数第二个节点，next指针中保存这尾节点的地址值，p指向尾节点
        (zbook)->next = p;//如果链表不为空则把链表尾指向p
    }
    zbook = p;
    cout << "添加成功,是否继续添加:是y，否n：" << endl;
    cin >> m;
    while (m != 'y' && m != 'n')
    {
        cout << "输入错误，请重新输入：" << endl;
        cin >> m;
    }
    if (m == 'y')
    {
        Addbook(&abook);
        exit(0);
    }
    else
    {
        cout << "正在返回到菜单，请勿操作" << endl;
        Sleep(200);
        system("cls");//清屏
        Menu();
        exit(0);
    }
}
void  LibraryManager::showbook(book* q)//显示图书信息
{
    book* m = q;//定义book类指针指向链表地址
    int k = 0, j = 0;//k控制换行，j记录书籍本书
    cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
    while (m != NULL)
    {
        cout << *m << endl;
        k++; j++;
        if (k > 10)//每 11个数据换行
        {
            cout << endl << endl; k = k - 11;
        }
        m = m->next;
    }
    cout << "一共展示" << j << "本图书" << endl;
    system("pause");
    cout << "正在返回到菜单，请勿操作" << endl;
    Sleep(200);
    system("cls");
    Menu();
    exit(0);
}
void  LibraryManager::amendbook(book* q)//修改图书信息
{
    string mp;
    char  h;
    book* p, ctemp;
    p = q;
    cout << "请输入要修改的图书的ISBN码：输入NO返回菜单" << endl;
    cin >> mp;
    if (mp == "NO") { system("cls"); Menu(); exit(0); }//返回菜单
    while (p != NULL)
    {
        if (p->getbookEntrynumber() == mp)break;//已查找到
        else { p = p->next; }
    }
    if (p == NULL)//未查找到
    {
        cout << "无此图书" << endl; 
        Sleep(300);
        amendbook(q);
        exit(0);
    }
    else
    {
        system("cls");
        ctemp = *p;
        cout << "以下为图书信息:" << endl;
        cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
        cout << *p << endl;
        cout << "********************************" << endl;
        cout << "本书ISBN0" << endl;
        cout << "本书书籍名称1" << endl;
        cout << "本书作者姓名2" << endl;
        cout << "本书分类3" << endl;
        cout << "本书出版单位4" << endl;
        cout << "本书出版时间5" << endl;
        cout << "本书书籍价格6" << endl;
        cout << "********************************" << endl;
        cout << "7返回菜单" << endl;
        cout << "请选择要修改的信息:0,1,2,3,4,5,6对应相应信息";
        try
        {
            cin >> h;
            if (h < '1' || h>'8') throw - 1;
        }
        catch (int)
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> h;
        }
        cout << "输入修改后的信息" << endl;
        switch (h)
        {
        case '0':p->m_bookEntrynumber(); break;
        case '1':p->m_bookname(); break;
        case '2':p->m_authorname(); break;
        case '3':p->m_booknumber(); break;
        case '4':p->m_publishaddress(); break;
        case '5':p->m_publishtime(); break;
        case '6':p->m_bookprice(); break;
        case '7':Sleep(200);
            system("cls");
            Menu();
            exit(0); break;
        }
        cout << "修改后图书信息为" << endl;
        cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
        cout << *p << endl;
        system("pause");
        cout << "无此图书" << endl; cout << "正在返回到菜单，请勿操作" << endl;
        Sleep(200);
        system("cls");
        Menu();
        exit(0);
    }
};
void  LibraryManager::SaveData(book* q)//保存图书数据在新文件中（ (若文件不存在则新建）
{
    book* m = q; book* btemp;
    fstream outfile("书籍信息.txt", ios::out);// 书籍信息.txt
    if (!outfile)
    {
        cout << "书籍文件保存失败" << endl;
        exit(0);
    }
    while (m != NULL)//链表不为空
    {
        outfile << *m;//把链表中数据输入文件保存，每保存一个释放一个
        btemp = m;
        m = m->next;
        delete btemp;//释放链表空间
    }
    outfile.close();//关闭文件
}
void  LibraryManager::FINDbook(book* q)//查找图书信息
{
    char p;
    cout << "按作者名查找书籍（请输入n）" << endl;
    cout << "按书籍名查找书籍（请输入s）" << endl;
    cout << "返回菜单（请输入f）" << endl;
    try
    {
        cin >> p;
        if (p!='n'&&p!='s'&&p!='f') throw - 1;
    }
    catch (int)
    {
        cout << "输入有误，请重新输入" << endl;
        cin >>p;
    }
    if (p == 'n')
    {
        string j;
        book* z;
        z = q;
        int i = 0;
        cout << "请输入需查找书籍的作者名" << endl;
        cin >> j;
        while (z != NULL)
        {
            if (z->getauthorname() == j)//已找到此书籍
            {
                cout << "该图书信息如下" << endl;
                cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
                cout << *z;
                z = z->next;
                i++;
            }
            else { z = z->next; }//未找到，继续寻找
        }
        if (z == NULL)//最终未找到
        {
            cout << "无此图书" << endl;
            Sleep(200);
            FINDbook(q);
            exit(0);
        }
        else
        {
            system("pause");
            system("cls");
            Menu();
            exit(0);
        }
    }

    else if(p=='s')// 按书名搜索
    {
        string j;
        book* z;
        z = q;
        int i = 0;
        cout << "请输入需查找书籍的书名" << endl;
        cin >> j;
        while (z != NULL)
        {
            if (z->getbookname() == j)//已找到此书籍
            {
                cout << "该图书信息如下" << endl;
                cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       	本书出版时间            本书书籍价格" << endl;
                cout << *z;
                z = z->next;
                i++;
            }
            else { z = z->next; }//未找到，继续寻找
        }
        if (z == NULL)//最终未找到
        {
            cout << "无此图书" << endl;
            Sleep(200);
            FINDbook(q);
            exit(0);
        }
        else
        {
            system("pause");
            system("cls");
            Menu();
            exit(0);
        }
    }
    else if (p == 'f')
    {
        system("pause");
        system("cls");
        Menu();
        exit(0);
    }
}
void  LibraryManager::Deletebook(book** q)//删除图书信息
{
    string m;//需输入的图书的登录号
    book* w; book* ww;
    w = *q;
    cout << "请输入需删除图书的ISBN码" << endl;
    cin >> m;
    if (w->getbookEntrynumber() == m)//从链表头找到该图书
    {
        cout << "该图书原本信息如下" << endl;
        cout <<"本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
        cout << *w;
        (*q) = (*q)->next;//移动链表头到下一位置
        delete w;//释放原链表头地址
        cout << "该图书信息已删除" << endl;
        Sleep(300);
        system("cls");
        Menu();
        exit(0);
        if (w == NULL)//最终未找到
        {
            cout << "无此图书" << endl;
            Sleep(300);
            Deletebook(q);
            exit(0);
        }
        else 
        {
            cout << "该图书原本信息如下" << endl;//已找到该图书
            cout << "本书ISBN              本书书籍名称          本书作者姓名              本书分类                 本书出版单位       本书出版时间            本书书籍价格" << endl;
            cout << *w;
            ww->next = w->next;
            delete w;//删除信息
            cout << "该图书信息已删除" << endl;
            Sleep(500);
            system("cls");
            Menu();
            exit(0);
        }
        while (w != NULL)
        {
            if (w->getbookEntrynumber() == m)break;
            else
            {
                ww = w;//锁定目标图书的下一地址
                w = w->next;
            }
        }
        if (w == NULL)
        {
            cout << "查询不到该图书" << endl << "正在返回" << endl;
            Sleep(500);
            Deletebook(q);
            exit(0);
        }
    }
    Sleep(200);
    system("cls");
    Menu();
    exit(0);
}
void  LibraryManager::sortbook(book* q)//按照价格排序（对整个链表进行排序 ）
{
    book* p = q, * m = q;
    int Long = 0, i, j;
    char k;
    cout << "1.按价格增长排序2.按价格降序排序" << endl;
    try
    {
        cin >> k;
        if (k < '1' || k>'2') throw - 1;
    }
    catch (int)
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> k;
    }
    while (m != NULL)//链表是否为空
    {
        Long++;//计算链表长度
        m = m->next;
    }
    m = q;
    for (i = 0; i < Long - 1; i++)
    {
        p = m;
        for (j = 0; j < Long - 1; j++)
        {
            if (k == '1') 
            {
                if (p->getbookprice() > p->next->getbookprice())//按价格增长排序
                {
                    p->Exchangebook(p->next);
                }
            }
            if (k == '2') 
            {
                if (p->getbookprice() < p->next->getbookprice())//按价格降序排序
                {
                    p->Exchangebook(p->next);
                }
            }
            p = p->next;
        }
    }
    cout << "图书正在排序中，请稍候" << endl;
    Sleep(200);
    system("cls");
    Menu();
    exit(0);
}
void book::Exchangebook(book* q)//交换书籍参数
{
    string book_Entry_number = this->getbookEntrynumber();
    string book_name = this->getbookname();
    string author_name = this->getauthorname();
    string book_number = this->getbooktype();
    string publish_address = this->getpublishaddress();
    string  publish_time = this->getpublishtime();
    string book_price = this->getbookprice();
    this->bookEntrynumber = q->getbookEntrynumber();
    this->bookname = q->getbookname();
    this->authorname = q->getauthorname();
    this->booktype = q->getbooktype();
    this->publishaddress = q->getpublishaddress();
    this->publishtime = q->getpublishtime();
    this->bookprice = q->getbookprice();
    q->bookEntrynumber = book_Entry_number;
    q->bookname = book_name;
    q->authorname = author_name;
    q->booktype = book_number;
    q->publishaddress = publish_address;
    q->publishtime = publish_time;
    q->bookprice = book_price;
}
int main()
{
    LibraryManager manager;
    manager.Menu();//调用菜单
    return 0;
}

