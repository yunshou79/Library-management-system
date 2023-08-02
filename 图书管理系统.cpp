#include<iostream>
#include<windows.h>//�� system("cls");����ʵ����������
#include <fstream>//���ļ����в�����������ͷ�ļ�
#include<stdio.h>//ʹ��Sleep()�������ͷ�ļ�
#include <cstring>
#include<iomanip>
using namespace std;
const unsigned  short MAX =11;
class book
{
private:
    string bookEntrynumber;//�鼮��¼��
    string bookname;//�鼮����
    string authorname;//��������
    string booktype;// �鼮����
    string publishaddress;//�鼮���浥λ
    string  publishtime;//�鼮����ʱ��
    string bookprice;//�鼮�۸�
public:
    book* next;
    string getbookEntrynumber()//get����ʵ��private�������������
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
    friend istream& operator>>(istream& in, book& p);//��������
    friend ostream& operator<<(ostream& out, book& p);//�������
    void  m_bookEntrynumber()//����ͼ������ book_Entry_number
    {
        cin >> bookEntrynumber;
    }
    void m_bookname()// ����ͼ������book_name
    {
        cin >> bookname;
    }
    void m_authorname()// ����ͼ������author_name
    {
        cin >> authorname;
    }
    void m_booknumber()// ����ͼ������book_number
    {
        cin >> booktype;
    }
    void m_publishaddress()// ����ͼ������publish_address
    {
        cin >> publishaddress;
    }
    void m_publishtime()// ����ͼ������publish_time
    {
        cin >> publishtime;
    }
    void m_bookprice()// ����ͼ������book_price
    {
        cin >> bookprice;
    }
    void Exchangebook(book* q);//����ͼ����Ϣ����
};
istream& operator>>(istream& in, book& p)//ʵ����������
{
    in >> p.bookEntrynumber >> p.bookname >> p.authorname >> p.booktype >> p.publishaddress >> p.publishtime >> p.bookprice;
    return in;
}
ostream& operator<<(ostream& out, book& p)//ʵ��������� ���̶�������ݿ��ΪMAX,����룬
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
class LibraryManager//ͼ��ݹ�����
{
public:
    LibraryManager();//ͼ�������Ĺ��캯
    void Menu();//ͼ�����ϵͳ�˵�
    void ExitManager();//�˳�ϵͳ
    void Addbook(book** q);//����ͼ����Ϣ
    void showbook(book* q);//��ʾͼ����Ϣ
    void Deletebook(book** q);//ɾ��ͼ����Ϣ
    void amendbook(book* q);//�޸�ͼ����Ϣ
    void FINDbook(book* q);//����ͼ����Ϣ
    void sortbook(book* q);//����ͼ��۸�����
    void Exchangebook(book* q);//����ʱ������Ϣ����
    void SaveData(book* q);//��ͼ�����ݱ��������ļ���
    int  initbook(book** q);//���ļ��ж���ͼ����Ϣ
private:
    book* abook;//book��ָ��ָ������ͷ
    book* zbook;//book��ָ��ָ������β
};
LibraryManager::LibraryManager()//ͼ�������Ĺ��캯��
{
    abook = NULL;
    initbook(&abook);//������ͷ����ַ���� init_book
}
int  LibraryManager::initbook(book** q)//���ļ��ж���ͼ����Ϣ
{
    int j = 0;//������¼��ȡ��Ϣ��
    ifstream infile("�鼮��Ϣ.txt", ios::in);//���鼮��Ϣ.txt�ļ��ж�ȡ����
    if (!infile)
    {
        cout << "�鼮����ʧ��" << endl; //�鼮����ʧ��
        Sleep(200);
        system("cls");
        return 0;
    }
    while (!infile.eof())
    {
        book* temp;
        temp = new book;
        infile >> (*temp);
        if (infile.eof()) { break; }//��ȡ���ļ�β������
        j++;
        if (*q == NULL)//��������Ƿ�Ϊ������
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
        cout << "�鼮�ļ�Ϊ��" << endl;
        Sleep(200);
        system("cls");
    }
    else 
    {
        cout << "���ļ��ж�ȡ����" << endl;
        Sleep(300);
        system("cls");
    }
    infile.close();
    return 1;
}
void LibraryManager::Menu()
{
    cout << "------------��ӭʹ��ͼ����Ϣ����ϵͳ------------------" << endl;
    cout << "        1---����ͼ����Ϣ      2---��ʾͼ����Ϣ " << endl;
    cout << "        3---ɾ��ͼ����Ϣ      4---�޸�ͼ����Ϣ " << endl;
    cout << "        5---����ͼ����Ϣ      6---���ռ۸����� " << endl;
    cout << "        7--ͼ�����ݱ��������ļ��в��˳�ϵͳ" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "����������ѡ��--->";
    char  m;
    try 
    {
        cin >> m;
        if (m < '1' || m>'8') throw - 1;
    }
    catch (int)
    {
        cout << "������������������" << endl;
        cin >> m;
    }
    switch (m)//�����û���ѡ����й���ʵ��
    {
    case '1':  Addbook(&abook); break;//����ͼ����Ϣ
    case '2':  showbook(abook); break;//��ʾͼ����Ϣ
    case '3':  Deletebook(&abook); break;//ɾ��ͼ����Ϣ
    case '4':  amendbook(abook); break;//�޸�ͼ����Ϣ
    case '5':  FINDbook(abook); break;//����ͼ����Ϣ
    case '6':  sortbook(abook); break;//���յ�¼������
    case '7':  SaveData(abook); cout << "��ӭ�´�ʹ��" << endl; exit(0); break;//��ͼ�����ݱ��������ļ���
    case '8':  initbook(&abook); break;
    }
}//���ļ��ж���ͼ����Ϣ
void  LibraryManager::Addbook(book** q)//����ͼ����Ϣ
{
    char m;
    cout << "������ͼ����Ϣ" << endl;
    book* p;//����book��ָ��
    p = new book;//Ϊp����洢�ռ�
    cout <<"����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
    cin >> *p;
    if (*q == NULL)//��������Ƿ�Ϊ������
    {
        p->next = NULL;
        *q = p;
    }//�������Ϊ���������ͷָ��p
    else
    {
        p->next = NULL;//p�ǵ����ڶ����ڵ㣬nextָ���б�����β�ڵ�ĵ�ֵַ��pָ��β�ڵ�
        (zbook)->next = p;//�������Ϊ���������βָ��p
    }
    zbook = p;
    cout << "��ӳɹ�,�Ƿ�������:��y����n��" << endl;
    cin >> m;
    while (m != 'y' && m != 'n')
    {
        cout << "����������������룺" << endl;
        cin >> m;
    }
    if (m == 'y')
    {
        Addbook(&abook);
        exit(0);
    }
    else
    {
        cout << "���ڷ��ص��˵����������" << endl;
        Sleep(200);
        system("cls");//����
        Menu();
        exit(0);
    }
}
void  LibraryManager::showbook(book* q)//��ʾͼ����Ϣ
{
    book* m = q;//����book��ָ��ָ�������ַ
    int k = 0, j = 0;//k���ƻ��У�j��¼�鼮����
    cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
    while (m != NULL)
    {
        cout << *m << endl;
        k++; j++;
        if (k > 10)//ÿ 11�����ݻ���
        {
            cout << endl << endl; k = k - 11;
        }
        m = m->next;
    }
    cout << "һ��չʾ" << j << "��ͼ��" << endl;
    system("pause");
    cout << "���ڷ��ص��˵����������" << endl;
    Sleep(200);
    system("cls");
    Menu();
    exit(0);
}
void  LibraryManager::amendbook(book* q)//�޸�ͼ����Ϣ
{
    string mp;
    char  h;
    book* p, ctemp;
    p = q;
    cout << "������Ҫ�޸ĵ�ͼ���ISBN�룺����NO���ز˵�" << endl;
    cin >> mp;
    if (mp == "NO") { system("cls"); Menu(); exit(0); }//���ز˵�
    while (p != NULL)
    {
        if (p->getbookEntrynumber() == mp)break;//�Ѳ��ҵ�
        else { p = p->next; }
    }
    if (p == NULL)//δ���ҵ�
    {
        cout << "�޴�ͼ��" << endl; 
        Sleep(300);
        amendbook(q);
        exit(0);
    }
    else
    {
        system("cls");
        ctemp = *p;
        cout << "����Ϊͼ����Ϣ:" << endl;
        cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
        cout << *p << endl;
        cout << "********************************" << endl;
        cout << "����ISBN0" << endl;
        cout << "�����鼮����1" << endl;
        cout << "������������2" << endl;
        cout << "�������3" << endl;
        cout << "������浥λ4" << endl;
        cout << "�������ʱ��5" << endl;
        cout << "�����鼮�۸�6" << endl;
        cout << "********************************" << endl;
        cout << "7���ز˵�" << endl;
        cout << "��ѡ��Ҫ�޸ĵ���Ϣ:0,1,2,3,4,5,6��Ӧ��Ӧ��Ϣ";
        try
        {
            cin >> h;
            if (h < '1' || h>'8') throw - 1;
        }
        catch (int)
        {
            cout << "�����������������" << endl;
            cin >> h;
        }
        cout << "�����޸ĺ����Ϣ" << endl;
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
        cout << "�޸ĺ�ͼ����ϢΪ" << endl;
        cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
        cout << *p << endl;
        system("pause");
        cout << "�޴�ͼ��" << endl; cout << "���ڷ��ص��˵����������" << endl;
        Sleep(200);
        system("cls");
        Menu();
        exit(0);
    }
};
void  LibraryManager::SaveData(book* q)//����ͼ�����������ļ��У� (���ļ����������½���
{
    book* m = q; book* btemp;
    fstream outfile("�鼮��Ϣ.txt", ios::out);// �鼮��Ϣ.txt
    if (!outfile)
    {
        cout << "�鼮�ļ�����ʧ��" << endl;
        exit(0);
    }
    while (m != NULL)//����Ϊ��
    {
        outfile << *m;//�����������������ļ����棬ÿ����һ���ͷ�һ��
        btemp = m;
        m = m->next;
        delete btemp;//�ͷ�����ռ�
    }
    outfile.close();//�ر��ļ�
}
void  LibraryManager::FINDbook(book* q)//����ͼ����Ϣ
{
    char p;
    cout << "�������������鼮��������n��" << endl;
    cout << "���鼮�������鼮��������s��" << endl;
    cout << "���ز˵���������f��" << endl;
    try
    {
        cin >> p;
        if (p!='n'&&p!='s'&&p!='f') throw - 1;
    }
    catch (int)
    {
        cout << "������������������" << endl;
        cin >>p;
    }
    if (p == 'n')
    {
        string j;
        book* z;
        z = q;
        int i = 0;
        cout << "������������鼮��������" << endl;
        cin >> j;
        while (z != NULL)
        {
            if (z->getauthorname() == j)//���ҵ����鼮
            {
                cout << "��ͼ����Ϣ����" << endl;
                cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
                cout << *z;
                z = z->next;
                i++;
            }
            else { z = z->next; }//δ�ҵ�������Ѱ��
        }
        if (z == NULL)//����δ�ҵ�
        {
            cout << "�޴�ͼ��" << endl;
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

    else if(p=='s')// ����������
    {
        string j;
        book* z;
        z = q;
        int i = 0;
        cout << "������������鼮������" << endl;
        cin >> j;
        while (z != NULL)
        {
            if (z->getbookname() == j)//���ҵ����鼮
            {
                cout << "��ͼ����Ϣ����" << endl;
                cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       	�������ʱ��            �����鼮�۸�" << endl;
                cout << *z;
                z = z->next;
                i++;
            }
            else { z = z->next; }//δ�ҵ�������Ѱ��
        }
        if (z == NULL)//����δ�ҵ�
        {
            cout << "�޴�ͼ��" << endl;
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
void  LibraryManager::Deletebook(book** q)//ɾ��ͼ����Ϣ
{
    string m;//�������ͼ��ĵ�¼��
    book* w; book* ww;
    w = *q;
    cout << "��������ɾ��ͼ���ISBN��" << endl;
    cin >> m;
    if (w->getbookEntrynumber() == m)//������ͷ�ҵ���ͼ��
    {
        cout << "��ͼ��ԭ����Ϣ����" << endl;
        cout <<"����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
        cout << *w;
        (*q) = (*q)->next;//�ƶ�����ͷ����һλ��
        delete w;//�ͷ�ԭ����ͷ��ַ
        cout << "��ͼ����Ϣ��ɾ��" << endl;
        Sleep(300);
        system("cls");
        Menu();
        exit(0);
        if (w == NULL)//����δ�ҵ�
        {
            cout << "�޴�ͼ��" << endl;
            Sleep(300);
            Deletebook(q);
            exit(0);
        }
        else 
        {
            cout << "��ͼ��ԭ����Ϣ����" << endl;//���ҵ���ͼ��
            cout << "����ISBN              �����鼮����          ������������              �������                 ������浥λ       �������ʱ��            �����鼮�۸�" << endl;
            cout << *w;
            ww->next = w->next;
            delete w;//ɾ����Ϣ
            cout << "��ͼ����Ϣ��ɾ��" << endl;
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
                ww = w;//����Ŀ��ͼ�����һ��ַ
                w = w->next;
            }
        }
        if (w == NULL)
        {
            cout << "��ѯ������ͼ��" << endl << "���ڷ���" << endl;
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
void  LibraryManager::sortbook(book* q)//���ռ۸����򣨶���������������� ��
{
    book* p = q, * m = q;
    int Long = 0, i, j;
    char k;
    cout << "1.���۸���������2.���۸�������" << endl;
    try
    {
        cin >> k;
        if (k < '1' || k>'2') throw - 1;
    }
    catch (int)
    {
        cout << "�����������������" << endl;
        cin >> k;
    }
    while (m != NULL)//�����Ƿ�Ϊ��
    {
        Long++;//����������
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
                if (p->getbookprice() > p->next->getbookprice())//���۸���������
                {
                    p->Exchangebook(p->next);
                }
            }
            if (k == '2') 
            {
                if (p->getbookprice() < p->next->getbookprice())//���۸�������
                {
                    p->Exchangebook(p->next);
                }
            }
            p = p->next;
        }
    }
    cout << "ͼ�����������У����Ժ�" << endl;
    Sleep(200);
    system("cls");
    Menu();
    exit(0);
}
void book::Exchangebook(book* q)//�����鼮����
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
    manager.Menu();//���ò˵�
    return 0;
}

