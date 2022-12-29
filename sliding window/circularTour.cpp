//https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1/

int tour(petrolPump p[], int n)
{
    // Your code here
    int count = 0, temp = 0;
    int l = 0, r = 0;
    while (count <= 2 * n)
    {
        temp += p[r].petrol - p[r].distance;
        count++;
        r = (r + 1) % n;
        if (temp < 0)
        {
            l = r;
            temp = 0;
        }
        else
        {
            if (l == r)
            {
                return l;
            }
        }
    }

    return -1;
}

// https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B

//https://leetcode.com/problems/gas-station/