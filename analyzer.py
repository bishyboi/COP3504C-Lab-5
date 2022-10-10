import stringdata
import time

def linear_search(container, element):
    # traverses every element in container until an element is equal t
    for i, data in enumerate(container):
        if data == element:
            return i
    # If no element is found return None
    return None

# Performs a binary search of a tuple 'container' looking for 'element'.
def binary_search(container, element):
    min = 0
    max = len(container) - 1
    mid = 0
    # Continue while bounds are still reasonable.
    while min <= max:
        # Calculate midpoint of max and min.
        mid = (max + min) // 2
        # Is element the same as container element?
        if container[mid] == element:
            return mid
        # Is element greater than container element?
        elif container[mid] > element:
            max = mid - 1
        # Is element less than container element?
        elif container[mid] < element:
            min = mid + 1
    return None

def main():
    time.perf_counter()
    # Generate Data
    data = stringdata.get_data()

    print("Search 'not_here' with linear_search.")

    time_start = time.time()
    index = binary_search(data, "not_here")
    # Calculate delta time
    time_delta = time.time() - time_start

    print("Time:", time_delta)

if __name__ == "__main__":
    main()