def solution(phone_book):

    phonelist=sorted(phone_book)
    length=len(phone_book)
    for k in range(length-1):
        strlen=len(phonelist[k])
        if phonelist[k]==phonelist[k+1][:strlen]:
            return False
    return True


print(solution(["119", "97674223", "1195524421"]))