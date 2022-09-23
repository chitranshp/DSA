//https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/

pair<long long, long long> getMinMax(long long a[], int n) 
{
    long long minele = a[0], maxele = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > maxele)
            maxele = a[i];
        else if(a[i] < minele)
            minele = a[i];
    }
    return make_pair(minele, maxele);
}