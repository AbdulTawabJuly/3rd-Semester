//#include <iostream>
//#include <list>
//using namespace std;
//struct Pump
//{
//    int fuel;
//    int distanceToNext;
//};
//int completeTheNonsenseTour(list<Pump>& pumps)
//{
//    if (pumps.size() <= 1)
//        throw std::logic_error("you are gay");
//    auto i = pumps.begin();
//    auto j = pumps.begin();
//    int balance = 0;
//    int count = 0;
//    int fuel, dist;
//    int idx = 0;
//    while (true)
//    {
//        dist = (*j).distanceToNext;
//        fuel = (*j).fuel;
//        balance += fuel;
//        if (balance - dist >= 0)
//        {
//            ++j;
//            if (j == pumps.end())
//            {
//                j = pumps.begin();
//                count = 0;
//            }
//            balance -= dist;
//        }
//        else
//        {
//            ++j;
//            if (j == pumps.end())
//            {
//                j = pumps.begin();
//                count = 0;
//            }
//            if (i == j)
//                return -1;
//            i = j;
//            count++;
//            idx = count;
//            balance = 0;
//            continue;
//        }
//        if (i == pumps.begin() && count != 0) // loop around
//            return -1;
//        count++;
//        if (i == j) //cycle completed
//            return idx;
//
//    }
//    return -1;//to avoid warning
//}
//int main()
//{
//    Pump p1, p2, p3, p4;
//    /*p1.fuel = 4;
//    p1.distanceToNext = 6;
//    p2.fuel = 6;
//    p2.distanceToNext = 5;
//    p3.fuel = 7;
//    p3.distanceToNext = 3;
//    p4.fuel = 4;
//    p4.distanceToNext = 5;*/
//    p1.fuel = 4;
//    p1.distanceToNext = 1;
//    p2.fuel = 3;
//    p2.distanceToNext = 8;
//    p3.fuel = 3;
//    p3.distanceToNext = 4;
//    p4.fuel = 5;
//    p4.distanceToNext = 2;
//    list<Pump> l = { p1,p2,p3,p4 };
//    cout << completeTheNonsenseTour(l) << endl;
//}