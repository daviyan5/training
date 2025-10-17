import bisect

class RangeArray:
    def __init__(self):
        self.ZEROES = -1
        self.bases = {}
        self.values = []
        
    def getRange(self, base, length=1):
        if not self.bases:
            raise RuntimeError("Array is empty")
            
        result = []
        current_base = base
        remaining = length
        
        while remaining > 0:
            if current_base in self.bases:
                idx, base_length = self.bases[current_base]
                use_length = min(remaining, base_length)
                result.extend(self.values[idx:idx+use_length])
                current_base += use_length
                remaining -= use_length
            else:
                next_base = self._getUpper(current_base)
                
                if next_base == float('inf'):
                    result.extend([0] * remaining)
                    break
                else:
                    zeros_length = min(remaining, next_base - current_base)
                    result.extend([0] * zeros_length)
                    current_base += zeros_length
                    remaining -= zeros_length
        
        return result
    
    def __getitem__(self, key):
        if isinstance(key, tuple):
            return self.getRange(key[0], key[1])
        return self.getRange(key, 1)[0]
            
    def _getMin(self):
        return min(list(self.bases.keys()))
        
    def _getMax(self):
        return max(list(self.bases.keys()))
        
    def _getLower(self, base):
        keys = list(self.bases.keys())
        if base <= keys[0]:
            return 0
        pos = bisect.bisect_left(keys, base)
        return keys[pos-1]
        
    def _getUpper(self, base):
        keys = list(self.bases.keys())
        if base >= keys[-1]:
            return float('inf')
        pos = bisect.bisect_right(keys, base)
        return keys[pos]
        
    def __setitem__(self, base, values):
        length = len(values)
        if not length:
            return
            
        if not self.bases:
            self.bases[base] = [0, length]
            self.values.extend(values)
            return
        
        affected_ranges = []
        for start, (idx, range_len) in self.bases.items():
            end = start + range_len
            if max(base, start) < min(base + length, end):
                affected_ranges.append((start, idx, range_len))
        
        if not affected_ranges:
            idx = len(self.values)
            self.bases[base] = [idx, length]
            self.values.extend(values)
        else:
            for start, idx, range_len in affected_ranges:
                end = start + range_len
                
                overlap_start = max(base, start)
                overlap_end = min(base + length, end)
                overlap_len = overlap_end - overlap_start
                
                existing_offset = overlap_start - start
                
                new_offset = overlap_start - base
                
                self.values[idx + existing_offset:idx + existing_offset + overlap_len] = values[new_offset:new_offset + overlap_len]
                
                if base + length > end and overlap_end == end:
                    remaining_start = end - base
                    remaining_values = values[remaining_start:]
                    self.__setitem__(end, remaining_values)
                
                if base < start and overlap_start == start:
                    prefix_len = start - base
                    prefix_values = values[:prefix_len]
                    idx = len(self.values)
                    self.bases[base] = [idx, prefix_len]
                    self.values.extend(prefix_values)
        
        # Sort bases by key
        sorted_items = sorted(self.bases.items())
        self.bases = dict(sorted_items)

if __name__ == "__main__":
    gt = [0 for i in range(25)]
    arr = RangeArray()
    
    arr[10] = [1, 2, 3, 4, 5]
    gt[10:15] = [1, 2, 3, 4, 5]
    print("Set arr[10] = [1, 2, 3, 4, 5]")
    print("Getting arr[10:15]:", arr[10, 5])
    print("Ground truth[10:15]:", gt[10:15])
    print("Match:", arr[10, 5] == gt[10:15])
    
    arr[20] = [6, 7, 8, 9, 10]
    gt[20:25] = [6, 7, 8, 9, 10]
    print("\nSet arr[20] = [6, 7, 8, 9, 10]")
    print("Getting arr[20:25]:", arr[20, 5])
    print("Ground truth[20:25]:", gt[20:25])
    print("Match:", arr[20, 5] == gt[20:25])
    
    arr[15] = [11, 12, 13]
    gt[15:18] = [11, 12, 13]
    print("\nSet arr[15] = [11, 12, 13]")
    print("Getting arr[15:18]:", arr[15, 3])
    print("Ground truth[15:18]:", gt[15:18])
    print("Match:", arr[15, 3] == gt[15:18])
    
    print("\nGetting arr[10:25]:", arr[10, 15])
    print("Ground truth[10:25]:", gt[10:25])
    print("Match:", arr[10, 15] == gt[10:25])
    
    arr[12] = [100, 101, 102, 103, 104]
    gt[12:14] = [100, 101, 102, 103, 104]
    print("\nSet arr[12] = [100, 101, 102, 103, 104]")
    print("Getting arr[10:18]:", arr[10, 8])
    print("Ground truth[10:18]:", gt[10:18])
    print("Match:", arr[10, 8] == gt[10:18])

    arr[11] = [66, 77, 88, 99]
    gt[11:15] = [66, 77, 88, 99]
    print("\nSet arr[11] = [66, 77, 88, 99]")
    print("Getting arr[10:18]:", arr[10, 8])
    print("Ground truth[10:18]:", gt[10:18])
    print("Match:", arr[10, 8] == gt[10:18])
    
    print("\nStorage info:")
    print("Bases:", arr.bases)
    print("Values:", arr.values)