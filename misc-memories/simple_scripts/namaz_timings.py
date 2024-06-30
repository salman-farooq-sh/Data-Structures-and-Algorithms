import json
import sys
import requests

url = r"https://api.aladhan.com/v1/timingsByCity?city=Gujranwala&country=Pakistan&method=1"  # 99&methodSettings=13,null,25"
response = requests.get(url)
json_data = response.json()

prayer_timings = json_data["data"]["timings"]

if (
    prayer_timings["Sunrise"] == "04:57"
    and prayer_timings["Fajr"] == "03:16"
    and prayer_timings["Isha"] == "20:53"
    or True
):
    print()
    for k, v in prayer_timings.items():
        print(f"{k:>10}", "->", v)
    print()
