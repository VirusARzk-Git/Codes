class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int lcm = p * q / __gcd(p, q);
        int x = lcm / q, y = lcm / p;
        if (y % 2 == 0)
            return 0;
        if(x % 2 == 0)
            return 2;
        return 1;
    }
};