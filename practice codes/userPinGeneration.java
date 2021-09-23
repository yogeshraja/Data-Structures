class UserMainCode {
    public String userIdGeneration(String input1, String input2, int input3, int input4) {
        String out = "", smaller = "", longer = "", pin = "";
        if (input1.length() > input2.length()) {
            smaller = input2;
            longer = input1;
        } else if (input1.length() < input2.length()) {
            smaller = input1;
            longer = input2;
        } else if (input1.compareTo(input2) < 0) {
            smaller = input1;
            longer = input2;
        } else {
            smaller = input2;
            longer = input1;
        }
        pin = Integer.toString(input3);
        out += smaller.charAt(smaller.length() - 1);
        out += longer;
        out += pin.charAt(input4 - 1);
        out += pin.charAt(pin.length() - input4);
        String result = "";
        for (char i : out.toCharArray()) {
            if (Character.isLetter(i)) {
                result += (char)(i ^ 0x20);
            } else {
                result += i;
            }
        }
        return result.toCharArray().toString();
    }

    public static void main(String[] args) {
        UserMainCode obj = new UserMainCode();
        System.out.println(obj.userIdGeneration("Manoj", "Kumar", 561327, 2));
    }
}