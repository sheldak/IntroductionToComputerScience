void zad2_4(int n){
    int sum = 0;
    for(int i = 1 ; i<=n; i++){
        int number = i;
        while(number>0){
            if(number%2==0){
                number/=2;
            }if(number%3==0){
                number/=3;
            }if(number%5==0){
                number/=5;
            }if(number==1){
                sum++;
                break;
            }else{
                break;
            }
        }
    }
    cout<<sum;
}