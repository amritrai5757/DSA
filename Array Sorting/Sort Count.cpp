//t.c=o(n+maxx)    s.c=o(maxx)
int maxx=0;
for(int i=0; i<arr.size(); i++)
    maxx= max(maxx,arr[i]);

int count[maxx]={0};

for(int i=0; i<arr.size(); i++)
    count[arr[i]]++;

for(int i=0; i<=maxx; i++){
    int tmp = count[i];
    while(tmp--)
        arr[i]=count[i];
}
