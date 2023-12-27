#include <bits/stdc++.h>
using namespace std;
#define ll long long


// ^ Set Matrix Zero

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

// ^ Pascal’s Triangle

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

// ^ Next Permutation

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

// ^ Kadane's Algorithm (Maximum Subarray Sum)

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
        
    }
    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

// ^ Sort an array of 0s, 1s and 2s (Dutch National Flag Algorithm)

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// ^ Stock Buy And Sell

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}


// ^ Rotate Image (90 degree) or Rotate Matrix

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

// ^ Merge Overlapping Intervals

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// ^ Merge two Sorted Arrays Without Extra Space

// ? Method 1: Insertion Sort Method
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// ? Method 2: Gap Method

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

// ^ Find the Duplicate Number (Floyd's Tortoise and Hare Algorithm)

int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

// ^ Find the Missing and Repeating Number

// ? Method 1: Using Maths
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

// ? Method 2: Using XOR

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

// ^ Count Inversions in an array

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

// ^ Search in a sorted 2D matrix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// ^ Pow(x, n) (Binary Exponentiation)

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
    if (nn % 2) {
        ans = ans * x;
        nn = nn - 1;
    } else {
        x = x * x;
        nn = nn / 2;
    }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

// ^ Find the Majority Element that occurs more than N/2 times

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

// ^ Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array

vector<int> majorityElement3(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

// ^ Grid Unique Paths | Count paths from left-top to the right bottom of a matrix

int uniquePaths(int m, int n) {
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

// ^ Count Reverse Pairs

void merge0(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge0(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

// ^ Two Sum : Check if a pair with given sum exists in Array

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

// ^ 4 Sum | Find Quads that add up to a target value

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}


// ^ Longest Consecutive Sequence in an Array


int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

// ^ Length of the longest subarray with zero Sum

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}

// ^ Count the number of subarrays with given xor K

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

// ^ Length of Longest Substring without any Repeating Character

int lengthofLongestSubstring(string s) {
    vector < int > mpp(256, -1);
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n) {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}


int main(){
    return 0;
}