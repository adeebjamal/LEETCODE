class Solution:
    def validIPAddress(self, IP: str) -> str:
        if "." in IP and ":" in IP: return "Neither"
        if len(IP)==0: return "Neither"

        if "." in IP:
            nums=IP.split(".")
            if len(nums)!=4: return "Neither"
            for num in nums:
                if not num.isdigit(): return "Neither"
                if int(num) not in range(0,256): return "Neither"
                if num[0]=="0" and len(num)>1: return "Neither"
            return "IPv4"

        if "::" in IP: return "Neither"

        if ":" in IP:
            nums=IP.split(":")
            if len(nums)!=8: return "Neither"
            for num in nums:
                if not num.isalnum(): return "Neither"
                if len(num)<0 or len(num)>4: return "Neither"
                for letter in num.lower():
                    if letter not in "abcdef0123456789": return "Neither"
        return "IPv6"