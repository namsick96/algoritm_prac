def solution(skill, skill_trees):
    answer=0
    for i in skill_trees:
        queue=list(skill)
        idx=0
        wrong=False
        for q in i:
            if q in skill:
                if queue[idx]==q:
                    idx+=1
                    continue
                else:
                    wrong=True
                    break
        if not wrong:
            answer+=1
    return answer