#pragma ident "$Id: EpochDataStore.cpp 2489 2010-12-02 16:52:07Z susancummins $"

/**
* @file EpochDataStore.cpp
* Class to handle interpolatable time serial data 
*/

//============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 2.1 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Wei Yan - Chinese Academy of Sciences . 2009, 2010, 2011
//
//============================================================================


#include "EpochDataStore.hpp"
#include "MiscMath.hpp"

namespace gpstk
{
   using namespace std;

      // get epoch list stored in this object
   EpochDataStore::EpochList EpochDataStore::epochList()
   {
      EpochList epochList;
      for(EpochData::const_iterator it = allData.begin();
         it != allData.end();
         ++it)
      {
         epochList.insert(it->first);
      }
      
      return epochList;
   }
   
      /* Edit the dataset, removing data outside the indicated time
       *  interval.
       *
       * @param[in] tmin defines the beginning of the time interval
       * @param[in] tmax defines the end of the time interval
       */
   void EpochDataStore::edit( DayTime tmin, DayTime tmax  )
      throw()
   {
      if(tmin > tmax) 
      {
         DayTime m= tmin;
         tmin = tmax;
         tmax = m;
      }

      if(tmin > finalTime) return;
      if(tmax < initialTime) return;

      EpochData::iterator it = allData.lower_bound(tmin);
      if(it != allData.begin())
      {
         allData.erase(allData.begin(), it);
      }

      it = allData.upper_bound(tmax);
      if(it != allData.end())
      {
         allData.erase(it, allData.end());
      }

      it = allData.begin();
      if(it == allData.end())
      {
         initialTime = DayTime::END_OF_TIME;
      }
      else
      {
         initialTime = it->first;
      }

      it = allData.end();
      if(--it == allData.end())
      {
         finalTime = DayTime::BEGINNING_OF_TIME;
      }
      else 
      {
         finalTime = it->first;
      }

   } // End of method 'EpochDataStore::edit()'
   
   
      // Add to the store directly
   void EpochDataStore::addData(const DayTime& time, 
                                const std::vector<double>& data)
        throw()
   {
      
      allData[time] = data;

      if((initialTime == DayTime::END_OF_TIME)    ||
         (finalTime == DayTime::BEGINNING_OF_TIME) )
      {
         initialTime = finalTime = time;
      }
      else if(time < initialTime) 
      {
         initialTime = time;
      }
      else if(time > finalTime) 
      {
         finalTime = time;
      }

   }  // End of method 'EpochDataStore::addData()'
   
   
      /* Get the VehiclePVData at the given epoch and return it.
       *  @param t DayTime at which to compute the EOPs.
       *  @return EarthOrientation EOPs at time t.
       *  @throw InvalidRequest if the epoch on either side of t
       *     cannot be found in the map.
       */
   std::vector<double> EpochDataStore::getData(const DayTime& t) const
         throw(InvalidRequest)
   {
      // check the time
      if( (t < initialTime) || (t > finalTime))
      {
         InvalidRequest ire(string("Time tag (")
            + t.asString()
            + string(") not found within the store "));
         GPSTK_THROW(ire);
      }

      EpochData::const_iterator it = allData.find(t);
      if(it != allData.end())
      {
         return it->second;
      }
      
     
      const int half = ( interPoints + 1 ) / 2;

      it = allData.lower_bound(t);   // i points to first element with key >= t

      if(t > finalTime) 
      { 
         it = allData.end();
         it--;
      }
 
      EpochData::const_iterator its = it;
      EpochData::const_iterator ite = it;

      if(allData.size()> 2*half)
      {
         int ileft = half;
         for(int i = 0; i < half; i++)
         {
            if(its==allData.begin()) break;
            its--;
            ileft--;
         }


         int iright = half-1+ileft;
         for(int i = 0; i < (half-1+ileft); i++)
         {
            ite++;

            if(ite == allData.end())
            {
               ite--;
               break;
            }

            iright--;
         }

         int ileft2 = iright; 
         for(int i = 0; i < iright; i++)
         {
            if(its == allData.begin()) break;
            its--;
            ileft2--;
         }

         if(ileft2 > 0)
         {
            // the code never go here
            // just throw an exception

            InvalidRequest e("My God, it should never go here!!!");
            GPSTK_THROW(e);
         }
      }
      else
      {
         its = allData.begin();
         ite = allData.end();
         ite--;
      }
      
      const int N = its->second.size();

      std::vector<double> times;
      std::vector<std::vector<double> > datas(N);
      
      ite++;
      for(EpochData::const_iterator itr=its; itr!=ite; itr++)
      {
         DayTime time = itr->first;
         std::vector<double> vd = itr->second;

         times.push_back(itr->first - its->first);
         
         if( vd.size() != N)
         {
            // Exception
            InvalidRequest e("Size of the data vector doesn't match!");
            GPSTK_THROW(e);
            
         }
         
         for(int i = 0; i < N; i++)
         {
            datas[i].push_back( vd[i] );
         }
      }
      
      std::vector<double> vd;

      double dt = t - its->first;
      double err(0.0);
      
      for(int i = 0; i < N; i++)
      {
         vd[i] = LagrangeInterpolation(times,datas[i],dt,err);
      }

      return vd;
   
   }  // End of method 'EpochDataStore::getPVData()'


}  // End of namespace gpstk









