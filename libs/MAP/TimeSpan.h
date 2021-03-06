/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/** 
* \file TimeSpan.h
* \brief Utility for representing a time span
* \author Lars-Åke Vinberg
*/

#ifndef TIMESPAN_H_
#define TIMESPAN_H_

#include <matime.h>

namespace MAPUtil
{
	/** 
	* \brief Class for representing a time span.
	* Span can be positive as well as negative.
	*/
	class TimeSpan
	//=========================================================================
	{
	public:
		/**
		 * Creates a timespan.
		 */
		TimeSpan( int ticks );
		/**
		 * Returns a new TimeSpan from the specified hours, minutes, and seconds.
		 */
		TimeSpan( int hours, int minutes, int seconds );
		/**
		 * Returns a new TimeSpan from the specified days, hours, minutes, and seconds.
		 */
		TimeSpan( int days, int hours, int minutes, int seconds );
		/**
		 * Returns the largest value that can be represented by a TimeSpan.
		 */
		static TimeSpan maxValue( );
		/**
		 * Returns the smallest value that can be represented by a TimeSpan.
		 */
		static TimeSpan minValue( );
		/**
		 * Returns zero as a TimeSpan.
		 */
		static TimeSpan zero( );
		/**
		 * Returns number of ticks in time span.
		 */
		time_t getTicks( ) const;
		/**
		 * Returns days component.
		 */
		int getDays( ) const;
		/**
		 * Returns hours component.
		 */
		int getHours( ) const;
		/**
		 * Returns minutes component.
		 */
		int getMinutes( ) const;
		/**
		 * Returns seconds component.
		 */
		int getSeconds( ) const;
		/**
		 * returns value in unit of days.
		 */
		double getTotalDays( ) const;
		/**
		 * Returns value in a unit of hours.
		 */
		double getTotalHours( ) const;
		/**
		 * Returns value in a unit of minutes.
		 */
		double getTotalMinutes( ) const;
		/**
		 * Returns value in a unit of seconds.
		 */
		double getTotalSeconds( ) const;
		/**
		 * Returns sum of two time spans, as a TimeSpan.
		 */
		TimeSpan add( TimeSpan ts ) const;
		/**
		 * Returns the absolute value of a TimeSpan, as a TimeSpan.
		 */
		TimeSpan duration( ) const;
		/**
		 * Returns negated value.
		 */
		TimeSpan negate( ) const;
		/**
		 * Returns difference between two time spans, as a TimeSpan.
		 */
		TimeSpan subtract( TimeSpan ts ) const;
		/**
		 * Returns a new TimeSpan from the specified days.
		 */
		static TimeSpan fromDays( double days );
		/**
		 * Returns a new TimeSpan from the specified hours.
		 */
		static TimeSpan fromHours( double hours );
		/**
		 * Returns a new TimeSpan from the specified minutes.
		 */
		static TimeSpan fromMinutes( double minutes );
		/**
		 * Returns the specified seconds, as a TimeSpan.
		 */
		static TimeSpan fromSeconds( double seconds );

	private:
		time_t mTicks;
	};
	/**
	 * Unary negation operator.
	 */
	inline TimeSpan operator - ( const TimeSpan& t )
	{ 
		return t.negate( ); 
	}
	/**
	 * Binary subtraction operator.
	 */
	inline TimeSpan operator - ( const TimeSpan& t1, const TimeSpan& t2 )	
	{ 
		return t1.subtract( t2 ); 
	}
	/**
	 * Binary addition operator.
	 */
	inline TimeSpan operator + ( const TimeSpan& t1, const TimeSpan& t2 )	
	{ 
		return TimeSpan( (int)t1.getTicks( ) + (int)t2.getTicks( ) ); 
	}
	/**
	 * Equality operator. Returns true if first timespan is equals to the second.
	 */
	inline bool operator == ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) == t2.getTicks( ); 
	}
	/**
	 * Inequality operator. Returns true if first timespan is not equal to the second.
	 */
	inline bool operator != ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) != t2.getTicks( ); 
	}
	/**
	 * Smaller than operator. Returns true if first timespan is smaller than the second.
	 */
	inline bool operator < ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) < t2.getTicks( ); 
	}
	/**
	 * Smaller than or equals operator. Returns true if first timespan is smaller than or equal to the second.
	 */
	inline bool operator <= ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) <= t2.getTicks( ); 
	}
	/**
	 * Larger than operator. Returns true if first operator is larger than the second
	 */
	inline bool operator > ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) > t2.getTicks( ); 
	}
	/**
	 * Larger than or equal operator. Returns true if first operator is larger than or equal to the second.
	 */
	inline bool operator >= ( const TimeSpan& t1, const TimeSpan& t2 )		
	{ 
		return t1.getTicks( ) >= t2.getTicks( ); 
	}
}

#endif // TIMESPAN_H_
