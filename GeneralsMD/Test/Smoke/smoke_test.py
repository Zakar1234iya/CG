"""Smoke test: launches game, loads test map, records 60s"""
import subprocess
import time
import sys
import platform

def main():
    exe = "ZeroHour.exe" if platform.system() == "Windows" else "ZeroHour"
    proc = subprocess.Popen(
        [exe, "-map", "TestMap1000Units", "-nosound"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    time.sleep(60)
    if proc.poll() is not None:
        print("FAIL: Game crashed before 60s")
        sys.exit(1)
    print("PASS: Game ran for 60s without crashing")
    proc.terminate()

if __name__ == "__main__":
    main()
