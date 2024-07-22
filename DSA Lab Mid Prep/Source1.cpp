////#include <bits/stdc++.h>
//#include<iostream>
//using namespace std;
//int SumOfSquNum(int givno)
//{
//    int SumOfSqr = 0;
//    while (givno)
//    {
//        SumOfSqr += (givno % 10) * (givno % 10);
//        givno /= 10;
//    }
//    return SumOfSqr;
//}
//bool checkHappy(int chkhn)
//{
//    int slno, fstno;
//    slno = fstno = chkhn;
//    do
//    {
//        slno = SumOfSquNum(slno);
//        fstno = SumOfSquNum(SumOfSquNum(fstno));
//    } while (slno != fstno);
//    return (slno == 1);
//}
//int main()
//{
//    int j, ctr;
//    cout << "\n\n Find the Happy numbers between 1 to 1000: \n";
//    cout << " ----------------------------------------------\n";
//    cout << " The Happy numbers between 1 to 1000 are: " << endl;
//    int i = 0;
//    for (j = 1000; j <= 9999; j++)
//    {
//        if (checkHappy(j))
//        {
//            cout << j << " ";
//            i++;
//        }
//
//    }
//    cout << endl<<endl;
//    cout << i;
//}