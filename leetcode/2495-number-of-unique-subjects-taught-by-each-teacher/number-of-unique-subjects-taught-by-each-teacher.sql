/* Write your PL/SQL query statement below */
select distinct t.teacher_id, (select count(distinct t2.subject_id) from teacher t2 where t.teacher_id = t2.teacher_id) as cnt from teacher t;