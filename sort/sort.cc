#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(const vector<int>& v)
{
  for(auto n : v) cout << n << " ";
  cout << endl;
}

//冒泡排序
void bubbleSort(vector<int>& v)
{
  for(int i = 0; i < v.size(); ++i)
  {
    int is_changed = 0;

    for(int j = 0; j < v.size() - i - 1; ++j)
    {
      if(v[j] > v[j + 1])
      { 
        swap(v[j],v[j + 1]);
        is_changed = 1;
      }
    }
    //未发生交换，说明已经有序
    if(!is_changed) return;
  }
  return ;
}

//选择排序算法
void selectSort(vector<int>& v)
{
  for(int i = 0; i < v.size(); ++i)
  {
    int k = i;
    for(int j = i + 1; j < v.size() ; ++j)
    {
      if(v[j] < v[k]) k = j;
    }
    swap(v[i], v[k]);
  }
  return;
}

//插入排序
void insertSort(vector<int> &v)
{
  for(int i = 1; i < v.size(); ++i)
  {
   int j = i;
   while(j != 0 && v[j] < v[j - 1])
   {
     swap(v[j], v[j - 1]);
     --j;
   }
  }
  return;
}

//希尔排序（分组的插入排序）
void shellSort(vector<int> &v)
{
  int gap = v.size()/2;
  while(gap > 0)
  {
    for(int i = gap; i < v.size(); ++i)
    {
      int j = i;
      while(j - gap >= 0 && v[j] < v[j - gap])
      {
        swap(v[j], v[j - gap]);
        j -= gap;
      }
    }
    gap /= 2;
  }
  return;
}

//二路归并排序
void Merge(vector<int> &v, int left, int mid, int right)
{
  int i = left, j = mid + 1;
  vector<int> result;
  while(i <= mid && j <= right)
  {
    if(v[i] < v[j])
    {
      result.push_back(v[i]);
      ++i;
    }else
    {
      result.push_back(v[j]);
      ++j;
    }
  }
  while(i <= mid) result.push_back(v[i++]);
  while(j <= right) result.push_back(v[j++]);
  for(auto n : result) v[left++] = n;
}

void MergeSort(vector<int> &v, int begin, int end)
{
  if(end <= begin) return;
  int mid = (end - begin)/2 + begin;
  MergeSort(v,begin,mid);
  MergeSort(v,mid + 1, end);
  Merge(v,begin,mid,end);
}

//快速排序
void quickSort(vector<int> &v, int left, int right)
{
  int i = left, j = right;
  if(i >= j) return;
  int pivot = v[i];
  while(i < j)
  {
    while(i < j && v[j] > pivot) --j;
    v[i] = v[j];
    while(i < j && v[i] <= pivot) ++i;
    v[j] = v[i];
  }
  v[i] = pivot;
  quickSort(v,left,i-1);
  quickSort(v,i+1,right);
}


//调整堆
void heapify(vector<int> &v, int index, int length)
{
  int max_index = index;
  //左子树的索引为2i + 1，右子树索引为 2i + 2，父节点索引为(i-1)/2
  max_index = (2*index + 1 < length && v[2*index + 1] > v[max_index]) ? 2*index + 1 : max_index;
  max_index = (2*index + 2 < length && v[2*index + 2] > v[max_index]) ? 2*index + 2 : max_index;

  //调整堆
  if(max_index != index)
  {
    swap(v[index], v[max_index]);
    heapify(v, max_index, length);
  }

}

//大顶堆排序
void heapSort(vector<int> &v)
{
  if(v.size() <= 1) return;
  int length = v.size();
  //构建堆，从最后一个非叶节点开始调整
  for(int i = v.size()/2 - 1; i >= 0; --i) heapify(v,i,length);
  while(length > 0)
  {
    //最后一个元素与堆顶元素调换
    swap(v[0],v[--length]);
    heapify(v,0,length);
  }
  
}

//桶排序
void bucketSort(vector<int> &v,int size)
{
  int min = v[0], max = v[0];
  for(auto n : v)
  {
    min = min < n ? min : n;
    max = max > n ? max : n;
  }
  int count = (max - min) / (size - 1);
  vector<vector<int>> bucket_list;
  for(int i = 0; i < size; ++i) bucket_list.push_back({});
  // count = (max - min) / (size - 1)，则(v[i] - min)/count一定不大于size-1
  for(int i = 0; i< v.size(); ++i) bucket_list[(v[i] - min)/count].push_back(v[i]);
  for(auto &bucket : bucket_list) sort(bucket.begin(),bucket.end());
  v.clear();
  for(auto &bucket : bucket_list)
  {
    for(auto n : bucket) v.push_back(n); 
  }

}

//计数排序
void countSort(vector<int> &v)
{
  int min = v[0], max = v[0];
  for(auto n : v)
  {
    min = min < n ? min : n;
    max = max > n ? max : n;
  }
  vector<int> count(max - min + 1, 0);
  for(auto n : v) count[n - min]++;
  v.clear();
  for(int i = 0; i < count.size(); ++i)
  {
    while(count[i]-- > 0)
    {
      v.push_back(i + min);
    }
  } 
}

int main()
{
  int n;
  vector<int> v;
  while(cin >> n)
  {
    v.push_back(n);
  }
  //bubbleSort(v);
  //selectSort(v);
  //insertSort(v);
  //shellSort(v);
  //MergeSort(v, 0, v.size() - 1);
  //quickSort(v,0,v.size() - 1);
  //heapSort(v);
  //bucketSort(v,3);
  countSort(v);
  print(v);

  return 0;
}