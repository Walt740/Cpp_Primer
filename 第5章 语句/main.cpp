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
//     cout << "请输入两个整数... \n" << endl;
//     while(cin >> a >> b)
//     {
//         try
//         {
//             if(b == 0)
//             {
//                 throw runtime_error("除数不能为0 \n") ;
//             }
//
//            cout << " 结果如下:\n"<< a << " / " << b <<" = "<< a / b << endl;
//         }
//         catch(runtime_error err)
//         {
//             cout <<"除数不能为0 \n"  /*err.what()*/ << endl;
//             cout << "需要继续码 （y or n）？";
//             char ch ;
//             cin >> ch ;
//             if( ch != 'Y' && ch != 'y')
//                break;
//         }
//     }
//     return 0;




//        do
//        {
//            cout << "请输入两个字符串： "<< endl;
//            string str1 , str2 ;
//            cin >> str1 >> str2 ;
//            if(str1.size() > str2.size())
//                cout << "长度较长的字符串是" << str1 <<endl ;
//
//            else if(str1.size() < str2.size())
//                cout << "长度较长的字符串是" << str2 <<endl ;
//            else
//                cout << "两个字符串相等" << endl;
//
//        }while(cin);
//
//        return 0;
//
//


//        string pre,cur;
//        bool b1 =  true;
//        cout <<"请输入一组字符串\n" <<endl;
//        while(cin >> cur)
//        {
//            if(cur == pre)
//            {
//                b1 = false;
//                cout << "连续出现的字符串是：" << cur << endl;
//                break;
//            }
//            pre = cur ;
//        }
//        if(b1)
//            cout << "没有出现两个连续的字符串 ！" << endl;
//        return 0;


//        string pre,cur;
//        bool b1 =  true;
//        cout <<"请输入一组字符串\n" <<endl;
//        while(cin >> cur)
//        {
//            if(!isupper(cur[0]))
//                continue;
//            if(cur == pre)
//            {
//                b1 = false;
//                cout << "连续出现的字符串是：" << cur << endl;
//                break;
//            }
//            pre = cur ;
//        }
//        if(b1)
//            cout << "没有出现两个连续的字符串 ！" << endl;
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
//            cout << "出现最多的字符串是：" << maxstring << "次数是：" << maxcnt << endl;
//        }
//        else
//        {
//            cout << "每个字符串都只出现一次 " <<endl;
//        }


    int cur_cnt = 0,max_cnt = 1;
    string cur_word,pre_word,rep_word;
    //svecu 用来存储最大重复次数不止一个的单词
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
        /*不能放在上一个else里面，否则输入形如
        how now cow cow cow 时输出 now 2.因为最后一个
        输入与前面相同，所以不会判断加上最后一次的cow
        */
        if(cur_cnt > max_cnt)
        {
            svec = nvec ;//如果后面出现了更大的重复次数的单词，则把以前的svec清空
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
            cout << "没有重复的单词" << endl;
    else
            for(auto iter = svec.begin(); iter != svec.end(); ++iter)
            cout << *iter << " " << max_cnt <<endl ;
    return 0;
}

