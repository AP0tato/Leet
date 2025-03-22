class Solution 
{
    public:
    bool isPalindrome(int x) 
    {
        long x1 = x;
        long y = 0;

        while(x1>0)
        {
            y += x1%10;
            x1 /= 10;
            if(x1>0)
                y *= 10;
        }

        return y==x;
    }
};