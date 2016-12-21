class Solution(object):
    def isAdditiveNumber(self, num):
        if len(num) < 3:
            return False
        for i in range(1,len(num)-1):
            if num[i] == '0':
                j = i + 1
                a = int(num[:i])
                b = int(num[i:j])
                tar = str(a+b)
                tarlen = len(tar)
                
                if len(num[j:]) < tarlen:
                    pass
                if len(num[j:]) == tarlen:
                    if num[j:] == tar:
                        return True
                    else:
                        pass
                else:
                    if num[j:j+tarlen] == tar:
                        if self.isAdditiveNumber(num[i:]):
                            return True
                    else:
                        pass
            else:
                for j in range(i+1,len(num)):
                        
                        a = int(num[:i])
                        b = int(num[i:j])
                        #å¤æ­å¦ææåå¯¼é¶
                        if len(num[:i]) > 1 and num[:i][0] == '0':
                            continue
                        if len(num[i:j]) > 1 and num[i:j][0] == '0':
                            continue
                        tar = str(a+b)
                        tarlen = len(tar)
                        #print tar
                        if len(num[j:]) < tarlen:
                            pass
                        if len(num[j:]) == tarlen:
                            if num[j:] == tar:
                                return True
                            else:
                                pass
                        else:
                            if num[j:j+tarlen] == tar:
                                if self.isAdditiveNumber(num[i:]):
                                    return True
                            else:
                                pass
                            
                
        return False
            
            
        