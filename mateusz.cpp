#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(string s){
    bool result = true;
    int i =0;
    int k =s.length()-1;
    while (i<k){
        if(s[i]!=s[k]){
            result = false;
            break;
        }
        i++;
        k--;
    }
    return result;
}

void zad1_2(){
    int a_s = 1;
    int b_s = 1;
    int a = 1;
    int b = 1;
    while(a!=2018){
        a = a+b;
        b=a-b;
        if(a>2018){
            if (a_s<=b_s){
                a_s++;
            } else{
                b_s++;
            }
            a=a_s;
            b=b_s;
        }
    }
    cout << a_s << " " << b_s;

}

void zad1_4(int n){
    int a = 1;
    int b = 1;
    vector<int> f = {1, 1};
    while(a<n){
        a=a+b;
        b=a-b;
        f.push_back(a);
    }
    int i, k, sum;
    i=0; k=0; sum =0;
    while (i<f.size() || k<f.size()){
        if(sum<n && i<f.size()){
            sum+=f[i++];
        } else if (sum>n){
            sum -= f[k++];
        } else if(sum<n){
            cout << "nie";
            break;
        } else{
            cout << "ok";
            break;
        }
    }
}


void zad1_14(int a, int b, int c){
    int mini = min(min(a,b),c);
    for (int i = mini; i > 0; i--) {
        if(c%i==0 && b%i==0 && a%i==0){
            cout << i;
            break;
        }

    }
}

void zad1_15(const int a, const int b, const int c){
    int a_curr = a;
    int b_curr = b;
    int c_curr = c;
    while (a_curr!=b_curr || b_curr!=c_curr){
        int maxi = max(max(a_curr,b_curr),c_curr);
        while(a_curr<maxi){
            a_curr+=a;
        }
        while(b_curr<maxi){
            b_curr+=b;
        }
        while(c_curr<maxi){
            c_curr+=c;
        }
    }
    cout << a_curr;
}

void zad1_16(){
    int n_start = 2;
    int i_max = 0;
    while (n_start <= 10000) {
        int n = n_start;
        int i = 0;
        while (n != 1) {
            n = (n % 2) * (3 * n + 1) + (1 - n % 2) * n / 2;
            if (++i > i_max) {
                i_max = i;
            }
        }
        n_start++;
    }
    cout << i_max;
}

void zad2_1(int n){
    int a = 1;
    int b = 1;
    vector<int> v = {a, b};
    while(a<n/2){
        a=a+b;
        b=a-b;
        v.push_back(a);
    }
    int i = v.size() - 1;
    int k = 0;
    while (i>k || k<i){
        if(v[i]*v[k]>n && i>k){
            i--;
        } else if(v[i]*v[k]<n && i>k){
            k++;
        } else{
            cout << "tak";
            break;
        }
    }
}

void zad2_2(int n){
    int a_n = 1;
    while (a_n<=n/2){
        a_n=a_n*a_n+a_n+1;
        if(n%a_n == 0){
            cout << "tak";
            break;
        }
    }
}

void zad2_3(int n){
    string num = to_string(n);

    if(!is_palindrome(num))
        return;
    num ="";
    while(n>0) {
        num += to_string(n%2);
        n/=2;
    }
    if(!is_palindrome(num))
        return;
    cout << "tak";
}

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

void zad2_5(int n){
    long result = 1;
    for (int i = 1; i <= n; ++i) {
        int number = i;
        //usuwamy zera z numeru
        while(number%10==0){
            number/=10;
        }
        result*=number;
        //usuwamy zera z wyniku
        while(result%10==0){
            result/=10;
        }
        //4 ostatnie cyfry wyniku wydaja sie wystarczajace zeby uzyskac poprawny wynik
        result%=10000;
    }
    cout << result%10;
}

int main() {
    zad2_5(1000000);
    return 0;
}
