const int maxn=100005;  //below maxn 1e5 sieve not works,but dont unneccerely increase otherwise tc will increase
vi allprime;   
int spf[maxn];  //nlognlogn

void sieve(){

    for (int i = 1; i <= maxn; i++)
        spf[i] = i;
    for (int i = 2; i * i <= maxn; i++) 
        if (spf[i] == i)
            for (int j = i + i; j <= maxn; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    /*for (int i = 2; i <= maxn; i++)  //for getting all prime numbers till maxn
        if (spf[i] == i)          
            allprime.push_back(i);
    */
}
