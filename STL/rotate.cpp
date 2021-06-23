#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

int arr[]={3,4,5,6,7,8};
int n=sizeof(arr)/sizeof(int);

rotate(arr,arr+3,arr+n);

for(int i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
return 0;

}