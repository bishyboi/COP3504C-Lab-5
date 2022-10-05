import stringdata as sd
import time

def linear_search(container, element: str):
    for word_idx in range(0,len(container)):
        if container[word_idx]==element:
            return word_idx
        
    return -1

def binary_search(container, element: str):
    min_idx= 0
    max_idx= len(container)-1
    
    middle_idx = (max_idx+min_idx)//2
    

    if container[middle_idx]==element:
        return middle_idx
    elif min_idx==middle_idx:
        return -1
    
    else:
        if container[middle_idx]> element:
            return binary_search(container[min_idx:middle_idx], element)
        else:
            return binary_search(container[middle_idx:max_idx], element)

def main():
    string_data = sd.get_data()
    test_string= ["not_here", "aaaaa", "mzzzz", "aegfe", "gerbe", "hello"]
    
    print()
    for string in test_string:
        print(f"Test word: {string}")
        
        init_time = time.time()
        print(linear_search(string_data, string))
        lin_time = time.time()- init_time
    
        print(binary_search(string_data, string))
        
        bin_time = time.time()- (lin_time + init_time)
        
        print(f"Linear Search Time: {lin_time}")
        print(f"Binary Search Time: {bin_time}")
        print("___________________________")
        print()
        
if __name__ == "__main__":
    main()