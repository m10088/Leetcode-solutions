[原题](https://leetcode.com/problems/validate-ip-address)

题意:


给定一个串，判断是不是ipv4还是ipv6，阅读理解题，使用python的try，catch可以避免处理大量的情况。


题解:

```Python
class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        legal = '0123456789abcdefABCDEF'
        try:
            ipv4 = IP.split('.')
            assert len(ipv4) == 4
            for i in range(4):
                for letter in ipv4[i]:
                        assert letter in legal
                assert ipv4[i][0] != '0' or (ipv4[i][0] == '0' and len(ipv4[i]) == 1) # 有前导0
                assert 0 <= int(ipv4[i]) <= 255
            return 'IPv4'
        except:
            try:
                ipv6 = IP.split(':')
                assert len(ipv6) == 8
                for i in range(8):
                    assert 0 < len(ipv6[i]) < 5
                    for letter in ipv6[i]:
                        assert letter in legal
                        
                return 'IPv6'
            except:
                return 'Neither'
```