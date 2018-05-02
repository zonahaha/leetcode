void merge(int *nums1, int m, int *nums2, int n) {
    int *res[m + n];
    int j = 0, k = 0;
    for (int i = 0; i < m + n; i++) {
        if (j < m && k < n)res[i] = nums1[j] < nums2[k] ? nums1[j++] : nums2[k++];
        else res[i] = j == m ? nums2[k++] : nums1[j++];
    }
    for (int i = 0; i < m + n; i++)nums1[i] = res[i];
}
