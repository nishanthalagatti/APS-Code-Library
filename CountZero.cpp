ll countZeroBit(ll x)
    {
        ll count = 0;
        while(x){
            if((x&1)==0)
                count++;
            x = x>>1;
        }
        return count;
    }
