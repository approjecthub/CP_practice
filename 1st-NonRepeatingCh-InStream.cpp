//https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

		string FirstNonRepeating(string A){
		    
		    int arr[26];
		    for(int i=0;i<26;i++){
		        arr[i] = 0;
		    }
		    
		    deque<char> st;
		    string ans = "";
		    for(char c: A){
		        if( arr[c-'a']==0){
		            st.push_back(c);
		            ans+=st.front();
		            arr[c-'a'] +=1;
		        }
		        else{
		            arr[c-'a'] +=1;
		            while(!st.empty()){
		                if(arr[st.front()-'a']<=1){
		                    ans += st.front();
		                    break;
		                }
		                else{
		                    st.pop_front();
		                }
		            }
		            
		            if(st.empty()){
		                ans+='#';
		            }
		        }
		    }
		    return ans;
		}
