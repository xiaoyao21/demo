int search(int* nums, int numsSize, int target){
	int start=0,end=numsSize-1;
	int middle;
	
	while(1){
		
	}
	loop:middle=(start+end)/2;

		if(nums[start]==target){
			return start;
		}
		else if(nums[start]>target){  
			if(nums[middle]==target){
				return middle;
			}
			else if(nums[middle]>target){
				if(nums[middle]>nums[start]){
					start=middle;
					goto loop;
				}else{
					end=middle;
				}
			}else{
				end=middle;
				goto loop;
			}
		}else{
			if(nums[middle]==target){
				return middle;
			}else if(nums[middle]>target){
				end=middle;
				goto loop;
			}else{
				if(nums[middle]>nums[start]){
					start=middle;
					goto loop;
				}else{
					end=middle;
					goto loop;
				}
			}
		}
	}
