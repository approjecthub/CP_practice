// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

function reverseParentheses(s: string): string {
    const stack: string[] = [];
    let currWord = '';
    for(const char of s){
        if(char === ')'){
            while(stack.length>=0 && stack[stack.length-1] !== '('){
                currWord += stack.pop();
            }

            stack.pop();
            stack.push(...currWord);
            currWord = '';
        }
        else{
            stack.push(char);
        }
    }
    return stack.join('');
};