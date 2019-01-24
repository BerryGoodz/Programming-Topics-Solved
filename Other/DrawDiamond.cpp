#include <iostream>
using namespace std;

void drawLine(int n)
{
    for(int i= 0 ; i < n; i ++) cout << "*";
}
void drawDiamond(int n)
{
    if(n <= 2) return; // size 2 or lower is not possible
    int half; // find iteration point where the line will have a space in between ex. ***** *****
    if(n % 2 == 0) half = n / 2 - 1;
    else half = n / 2;
    int storeHalf = half;// store the half number to use it in the while loop conditional statement
    drawLine(n);//first line (no spaces)
    cout << endl;
    bool doReverse = false;//when this is true, the half will start increasing in the loop, which will draw the other half of the diamond
    do
    {
        drawLine(half);
        for(int i = 0; i < n - half * 2; i ++) cout << " "; //spaces between the lines
        drawLine(half);
        cout << endl;

        if(half == 1) doReverse = true;
        if(doReverse) half ++;
        else half --;
    }while(half != storeHalf + 1);
    drawLine(n);//last line
}
int main() {
   drawDiamond(25);
   return 0;
}
