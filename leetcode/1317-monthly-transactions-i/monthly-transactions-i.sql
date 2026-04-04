select distinct
    to_char(t.trans_date, 'yyyy-mm') as month,
    t.country,
    nvl(
        (
            select count(*)
            from transactions t2
            where to_char(t.trans_date, 'yyyy-mm') = to_char(t2.trans_date, 'yyyy-mm')
              and (t2.country = t.country or (t2.country is null and t.country is null))
        ),
        0
    ) as trans_count,
    nvl(
        (
            select count(*)
            from transactions t3
            where to_char(t.trans_date, 'yyyy-mm') = to_char(t3.trans_date, 'yyyy-mm')
              and (t3.country = t.country or (t3.country is null and t.country is null))
              and t3.state = 'approved'
        ),
        0
    ) as approved_count,
    nvl(
        (
            select sum(t4.amount)
            from transactions t4
            where to_char(t.trans_date, 'yyyy-mm') = to_char(t4.trans_date, 'yyyy-mm')
              and (t4.country = t.country or (t4.country is null and t.country is null))
        ),
        0
    ) as trans_total_amount,
    nvl(
        (
            select sum(t5.amount)
            from transactions t5
            where to_char(t.trans_date, 'yyyy-mm') = to_char(t5.trans_date, 'yyyy-mm')
              and (t5.country = t.country or (t5.country is null and t.country is null))
              and t5.state = 'approved'
        ),
        0
    ) as approved_total_amount
from transactions t;