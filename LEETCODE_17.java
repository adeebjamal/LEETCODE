import java.util.*;

class Solution {
    List<String> answer = new ArrayList<>();
    Map<Character, String> hash = new HashMap<>();
    void solve(int index, List<Character> combination, String digits) {
        if(index >= digits.length()) {
            String str = "";
            for(Character letter: combination) {
                str += letter;
            }
            this.answer.add(str);
            return;
        }
        String letters = this.hash.get(digits.charAt(index));
        for(int i = 0; i < letters.length(); i++) {
            combination.add(letters.charAt(i));
            this.solve(index + 1, combination, digits);
            combination.remove(combination.size() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) {
            return new ArrayList<>();
        }
        this.hash.put('2', "abc");
        this.hash.put('3', "def");
        this.hash.put('4', "ghi");
        this.hash.put('5', "jkl");
        this.hash.put('6', "mno");
        this.hash.put('7', "pqrs");
        this.hash.put('8', "tuv");
        this.hash.put('9', "wxyz");
        this.solve(0, new ArrayList<>(), digits);
        return this.answer;
    }
}