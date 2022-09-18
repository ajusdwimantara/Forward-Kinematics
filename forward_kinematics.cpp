#include<iostream>
#include<cmath>

using namespace std;

void fkM(float l[], float a[], int n){
	float x[n+1],y[n+1];
	for(int i=0;i<n+1;i++){
		x[i-1] = 0.;
	}
	for(int i=0;i<n+1;i++){
		y[i-1] = 0.;
	}

	cout<<" initial position :\n";
	float totalLen = 0;
	for(int i=0;i<n;i++){
		totalLen += l[i];
		cout<<totalLen<<", "<<y[i]<<endl;
	}
	cout<<endl;
	float totalDegre=0;
	for(int i=0;i<n;i++){
		totalDegre += a[i];
		y[i] = (sin(totalDegre) * l[i]) + y[i-1];
		x[i] = (cos(totalDegre) * l[i]) + x[i-1];
	}
	cout<<" final position :\n";
	for(int i=0;i<n;i++){
		cout<<x[i]<<", "<<y[i]<<endl;
	}
}

int main(){
	const float pi = 3.14;
	int n;
	
	cout<<"how many joint\t: ";cin>>n;
	cout<<"joints\t\t: "<<n<<"\n";
	
	float l[n];
	float a[n];
	
	for(int i=0;i<n;i++){
		cout<<"length of link-"<<i+1<<" from the reference point: ";cin>>l[i];
		cout<<"angular rotate of joint-"<<i+1<<": ";cin>>a[i];
		a[i] = (a[i]/180) * pi;
		cout<<endl;
	}

	fkM(l,a,n);
}
