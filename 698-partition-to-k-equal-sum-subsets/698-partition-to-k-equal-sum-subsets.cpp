class Solution {
public:
   // use global variables to avoid long parameter list
   int target; // of each bucket
   vector< int > ns;
   vector< int > bucket;

   bool canPartitionKSubsets( vector<int>& nums, int k ) {
       int sum = 0;
       for( int &n : nums ) 
           sum += n;
       
       if( sum % k ) 
           return false; // not divisible
       
       target = sum / k;
       ns = vector< int >( nums );
       bucket = vector< int >( k, 0 );
       
       // starting with bigger ones makes it faster
       sort( ns.begin(), ns.end() );
       reverse( ns.begin(), ns.end() );
       
       return put( 0 );
   }

   // put #n item of ns into some bucket to meet target
   bool put( int n ) {
       if(n == ns.size())
           return true;
       
       for( int i = 0; i < bucket.size(); ++i ) {
           if( bucket[i] + ns[n] > target ) 
               continue; // try next bucket
           
           bucket[i] += ns[n]; // put it in!
           
           if( put( n + 1 ) ) 
               return true; // move on to next item
           
           bucket[i] -= ns[n]; // take it out
           if(bucket[i] == 0)
                   return false;
       }
       return false; // no bucket fits
   }
};