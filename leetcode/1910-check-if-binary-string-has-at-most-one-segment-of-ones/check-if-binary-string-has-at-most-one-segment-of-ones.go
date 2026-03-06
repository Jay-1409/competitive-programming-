func checkOnesSegment(s string) bool {
    cnt := 0;
    prev := '0';
    for i:=0; i < len(s); i++ {
        if s[i] == '1' && prev == '0' {
            cnt++;
            prev = '1';
        } else if s[i] == '0'{
            prev = '0'
        }
    }
    return cnt <= 1;
}