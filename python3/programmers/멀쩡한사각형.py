def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

def solution(w,h):
    if w==h:
        return w*h-w
    else:
        if w>h:
            return w*h-(w+h-gcd(w,h))
        else:
            return w*h-(w+h-gcd(h,w))

    return answer

a=solution(8,12)
print(a)