#include <iostream>
#include <vector>
using namespace std;

int main()
{
//    int sum =0,val = 1;
//    while(val <= 10)
//        sum+=val,
//        ++val;
//    cout << "Sum of 1 to 10 inclusive is "<< sum << endl;

//    int num ;
//    cin >> num ;int a=10,b=11,c=12,d=13;
//    switch(num)
//    {
//        case 1: //int a=10,b=11,c=12,d=13;
//            break;
//        case 2:
//                cout << a <<b<< c<<d<<endl ;
//            break;
//        default: break;
//    }
//    return 0 ;


////    unsigned int ffcnt = 0,flcnt = 0,ficnt = 0;
////    char ch,prech = '/0';
////    while(cin >> ch)
////    {
////        bool b1 = true ;
////        if(prech == 'f')
////        {
////            switch(ch)
////            {
////                case 'f' : ++ffcnt;
////                    b1 = false;
////                    break;
////                case 'l' : ++flcnt;
////                    break;
////                case 'i' : ++ficnt;
////                default:
////                    break;
////            }
////
////        }
////        if(b1 == true)
////            {
////                prech = ch ;
////            }
////            else
////            {
////                prech = '\0';
////            }
////    }
////    cout << "ffcnt" << " " << ffcnt <<endl ;
////    cout << "ficnt" << " " << ficnt <<endl ;
////    cout << "flcnt" << " " << flcnt <<endl ;









//    unsigned int ffcnt = 0 ,flcnt = 0, ficnt = 0;
//    char ch , prech = '/0';
//    bool b1 = true ;
//    while(cin >> ch)
//    {
//
//
//        if(prech == 'f')
//        {
//            switch(ch)
//            {
//                case 'f' :  ++ffcnt ;
//                            b1 = false;
//                    break;
//                case 'i' :  ++ficnt ;
//                    break;
//                case 'l' :  ++flcnt ;
//                default:break;
//            }
//        }
//        if(!b1)
//            prech = '\0';
//        else
//            prech = ch;
//    }
//    cout << "ffcnt " << ffcnt <<endl ;
//    cout <<"ficnt "<< ficnt <<endl;
//    cout << "flcnt "<< flcnt << endl;





//    do
//    {
//        ;
//    }while(int ival = 0)

//     int a, b;
//     cout << "��������������... \n" << endl;
//     while(cin >> a >> b)
//     {
//         try
//         {
//             if(b == 0)
//             {
//                 throw runtime_error("��������Ϊ0 \n") ;
//             }
//
//            cout << " �������:\n"<< a << " / " << b <<" = "<< a / b << endl;
//         }
//         catch(runtime_error err)
//         {
//             cout <<"��������Ϊ0 \n"  /*err.what()*/ << endl;
//             cout << "��Ҫ������ ��y or n����";
//             char ch ;
//             cin >> ch ;
//             if( ch != 'Y' && ch != 'y')
//                break;
//         }
//     }
//     return 0;




//        do
//        {
//            cout << "�����������ַ����� "<< endl;
//            string str1 , str2 ;
//            cin >> str1 >> str2 ;
//            if(str1.size() > str2.size())
//                cout << "���Ƚϳ����ַ�����" << str1 <<endl ;
//
//            else if(str1.size() < str2.size())
//                cout << "���Ƚϳ����ַ�����" << str2 <<endl ;
//            else
//                cout << "�����ַ������" << endl;
//
//        }while(cin);
//
//        return 0;
//
//


//        string pre,cur;
//        bool b1 =  true;
//        cout <<"������һ���ַ���\n" <<endl;
//        while(cin >> cur)
//        {
//            if(cur == pre)
//            {
//                b1 = false;
//                cout << "�������ֵ��ַ����ǣ�" << cur << endl;
//                break;
//            }
//            pre = cur ;
//        }
//        if(b1)
//            cout << "û�г��������������ַ��� ��" << endl;
//        return 0;


//        string pre,cur;
//        bool b1 =  true;
//        cout <<"������һ���ַ���\n" <<endl;
//        while(cin >> cur)
//        {
//            if(!isupper(cur[0]))
//                continue;
//            if(cur == pre)
//            {
//                b1 = false;
//                cout << "�������ֵ��ַ����ǣ�" << cur << endl;
//                break;
//            }
//            pre = cur ;
//        }
//        if(b1)
//            cout << "û�г��������������ַ��� ��" << endl;
//        return 0;

//        string currstring ,prestring = " ",maxstring;
//        int curcnt = 1,maxcnt = 0;
//
//        while(cin >> currstring)
//        {
//           if(currstring == prestring)
//           {
//               curcnt++;
//               if(curcnt > maxcnt)
//               {
//                    maxcnt = curcnt;
//                    maxstring = currstring;
//               }
//           }
//           else
//           {
//               curcnt = 1;
//           }
//           prestring = currstring;
//        }
//        if(maxcnt >1)
//        {
//            cout << "���������ַ����ǣ�" << maxstring << "�����ǣ�" << maxcnt << endl;
//        }
//        else
//        {
//            cout << "ÿ���ַ�����ֻ����һ�� " <<endl;
//        }


    int cur_cnt = 0,max_cnt = 1;
    string cur_word,pre_word,rep_word;
    //svecu �����洢����ظ�������ֹһ���ĵ���
    vector<string>svec,nvec;
    while(cin >> cur_word)
    {
        if(pre_word == cur_word)
        {
            ++cur_cnt;
        }
        else
        {
            cur_cnt = 1;
            pre_word = cur_word;
        }
        /*���ܷ�����һ��else���棬������������
        how now cow cow cow ʱ��� now 2.��Ϊ���һ��
        ������ǰ����ͬ�����Բ����жϼ������һ�ε�cow
        */
        if(cur_cnt > max_cnt)
        {
            svec = nvec ;//�����������˸�����ظ������ĵ��ʣ������ǰ��svec���
            max_cnt = cur_cnt;
            rep_word = pre_word;
            svec.push_back(rep_word);
        }
        else if(cur_cnt > 1 && cur_cnt == max_cnt)
        {
            svec.push_back(pre_word);
        }
    }
    if(max_cnt == 1)
            cout << "û���ظ��ĵ���" << endl;
    else
            for(auto iter = svec.begin(); iter != svec.end(); ++iter)
            cout << *iter << " " << max_cnt <<endl ;
    return 0;
}

