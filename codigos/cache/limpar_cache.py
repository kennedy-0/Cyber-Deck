import os
import time

while True:
        os.system("sync")
        with open("/proc/sys/vm/drop_caches", "w") as f:
                f.write("3\n")

        time.sleep(30)

