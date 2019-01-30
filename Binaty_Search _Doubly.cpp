bool ok(double v){
	//some thing here
}
 
double binarySearch(){
	double lo = 0, med, hi = 1e9;
	int cnt = 10000;
	while(cnt--){
		med = (lo + hi) / 2.0;
		if(ok(med))		hi = med;			//lo = med;
		else lo = med //hi = med;
	}
	return lo;
}
 
int main() {
	cout << binarySearch() << endl;
	return 0;
}