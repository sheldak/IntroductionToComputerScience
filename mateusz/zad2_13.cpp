void zad2_13(){
    vector<int> v;
    while (v[v.size()-1]!=0){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int pos=0;
    int suma_sasiadow = 1;
    int suma = 0;
    while(pos<v.size()){
        suma_sasiadow+=v[(pos-2<0)?pos+3:pos-2];
        suma_sasiadow+=v[(pos-1<0)?pos+4:pos-1];
        suma_sasiadow+=v[(pos+1>v.size()-1)?pos-4:pos+1];
        suma_sasiadow+=v[(pos+2>v.size()-1)?pos-3:pos+2];
        if(suma_sasiadow/4==v[pos]){
            suma++;
        }
        suma_sasiadow=1;
        pos++;
    }
    cout<<suma;
}