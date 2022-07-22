void factor(int n,vi &ans){
    int temp=0;
    while (n> 1){
        //if(temp!=spf[n])   //for unique prime factors 2 3 not 2 2 3
            ans.pb(spf[n]);  
        //temp=spf[n];
        n/= spf[n];
    }
}
