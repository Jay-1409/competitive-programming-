class Robot {
    int dxn = 0;
    int x, y;
    int xbound, ybound;
    int perimeter;
    public Robot(int width, int height) {
        dxn = 0;
        x = 0;
        y = 0;
        xbound = width;
        ybound = height;
        perimeter = 2 * (width + height) - 4;
    }
    public int getMaxPossibleMovesInDxn() {
        if(dxn == 0) {
            return xbound - x - 1;
        } else if(dxn == 1) {
            return ybound - y - 1;
        } else if(dxn == 2) {
            return x;
        }
        return y;
    }
    public void applyStepsInDxn(int step) {
        if(dxn == 0) {
            x += step;
        } else if(dxn == 1){
            y += step;
        } else if(dxn == 2) {
            x -= step;
        } else {
            y -= step;
        }
    }
    public void step(int num) {
        num = (num % perimeter == 0 ? num = perimeter : num % perimeter);
        int maxChange = getMaxPossibleMovesInDxn();
        int doChange = Math.min(maxChange, num);
        num -= doChange; 
        applyStepsInDxn(doChange);
        if(num > 0) {
            dxn = (dxn + 1) % 4;
            step(num);
        }       
    }
    public int[] getPos() {
        int arr[] = new int[2];
        arr[0] = x;
        arr[1] = y;
        return arr;
    }
    
    public String getDir() {
        if(dxn == 0) {
            return "East";
        } else if(dxn == 1) {
            return "North";
        } else if(dxn == 2) {
            return "West";
        } else {
            return "South";
        }
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.step(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */