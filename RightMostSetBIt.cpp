void findRightMostSetBit(ll n)
{
        ll rmsb = n & ~(n-1);
        
        return log2(rmsb) + 1;		// +1 added for 1th index
}
