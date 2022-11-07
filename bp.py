import random
import time

def run(do_bp):
    num = 1_000_000
    ttimes = 1_000
    count = 0


    arr = [random.randint(0, 1) for x in range(num)]

    if do_bp:
        arr.sort()

    start = time.time()

    for times in range(0, ttimes):
        for i in range(0, num):
            if 0 == arr[i]:
                count += 1

    end = time.time()

    print("[PY3]: Counter: " + str(count) + " with branch prediction: " + str(do_bp) + " in " + str(int(end - start)) + "s")

if __name__ == "__main__":
    run(False)
    run(True)